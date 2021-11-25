import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
from VoiceClassificationModel import VoiceClassificationModel
from voiceDataset import VoiceDataset, pad_collate
import encodeAndDecode

# 配置运行设备
# set device
if torch.cuda.is_available():
    device = 'cuda'
else:
    device = 'cpu'


def train_loop(model, dataloader, loss_function, optimizer, scheduler, epoch):
    print("-----start train----")
    data_len = len(dataloader.dataset)
    model.train()
    for batch, (spectrogram, pinyin_labels, input_lengths, label_lengths, _) in enumerate(dataloader):
        spectrogram, pinyin_labels = spectrogram.to(device), pinyin_labels.to(device)
        # batch, time, n_class
        pred = model(spectrogram)
        pred = F.log_softmax(pred, dim=2)
        # time, batch, n_class
        pred = pred.transpose(0, 1)
        loss = loss_function(pred, pinyin_labels, input_lengths, label_lengths)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        scheduler.step()
        if batch % 100 == 0 or batch == data_len:
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch * len(spectrogram), data_len,
                       100. * batch / len(dataloader), loss.item()))


def test_loop(model, dataloader, loss_function):
    print("-----start evaluate----")
    test_loss = 0
    chinese_cer, pinyin_cer = [], []
    model.eval()
    with torch.no_grad():
        for index, (spectrogram, pinyin_labels, input_lengths, label_lengths, chinese_labels) in enumerate(dataloader):
            if index == 10:
                break
            spectrogram, pinyin_labels = spectrogram.to(device), pinyin_labels.to(device)
            # batch, time, n_class
            pred = model(spectrogram)
            pred = F.log_softmax(pred, dim=2)
            # time, batch, n_class
            pred = pred.transpose(0, 1)
            loss = loss_function(pred, pinyin_labels, input_lengths, label_lengths)
            test_loss += loss.item() / len(dataloader)
            decoded_preds, decoded_targets = encodeAndDecode.decode.greed_decode(pred.transpose(0, 1), pinyin_labels,
                                                                                 label_lengths)
            # 计算 Character Error Rate
            for j in range(len(decoded_preds)):
                target = chinese_labels[j]
                pred_str, pred_pinyin = encodeAndDecode.decode.pinyin2chinese(decoded_preds[j])
                chinese_cer.append(encodeAndDecode.cer(target, pred_str))
                pinyin_cer.append(encodeAndDecode.cer(''.join(decoded_targets[j]), ''.join(decoded_preds[j])))
                # print to terminal
                if index % 10 == 0:
                    target_pinyin = []
                    for i in range(0, len(decoded_targets[j]), 2):
                        target_pinyin.append(decoded_targets[j][i] + decoded_targets[j][i + 1])
                    print('Predict_chinese: {} \n Predict_pinyin: {}\n target_pinyin: {}\n target_chinese: {}'.format(
                        pred_str, pred_pinyin,
                        ' '.join(target_pinyin), target))

    avg_chinese_cer = sum(chinese_cer) / len(chinese_cer)
    avg_pinyin_cer = sum(pinyin_cer) / len(pinyin_cer)
    print(
        'Test set: Average loss: {:.4f}, Average chinese CER: {:4f}, Average pinyin CER: {:4f}\n'.format(test_loss,
                                                                                                         avg_chinese_cer,
                                                                                                         avg_pinyin_cer))


if __name__ == "__main__":
    # 训练参数
    # train param
    params = {
        "n_cnn_layers": 3,  # cnn层数
        "n_rnn_layers": 5,  # rnn(gru)层数
        "rnn_dim": 512,  # rnn维度
        "n_class": 220,  # 输出特征数
        "n_feats": 40,  # 与n_mfcc相同
        "stride": 2,  # 步长
        "dropout": 0.1,  # dropout rate
        "learning_rate": 5e-4,  # 学习率
        "batch_size": 10,  # 训练时的batch大小
        "epochs": 1  # 训练轮数
    }
    # dataset 数据集
    training_data = VoiceDataset(path="../dataset/voice/data_thchs30", train=True)
    test_data = VoiceDataset(path="../dataset/voice/data_thchs30", train=False)
    # dataloader
    train_dataloader = DataLoader(training_data, batch_size=params['batch_size'], collate_fn=lambda b: pad_collate(b),
                                  shuffle=True)
    test_dataloader = DataLoader(test_data, batch_size=params['batch_size'], collate_fn=lambda b: pad_collate(b),
                                 shuffle=True)
    # model
    # myModel = VoiceClassificationModel(params['n_cnn_layers'], params['n_rnn_layers'], params['rnn_dim'],
    #                                    params['n_class'], params['n_feats'], params['stride'], params['dropout']).to(
    #     device)
    # 加载model
    myModel = torch.load('../param/voice_nnf_40.pth')
    # loss_fn and optimizer
    opt = torch.optim.AdamW(myModel.parameters(), params['learning_rate'])
    loss_fn = nn.CTCLoss(blank=0).to(device)
    # scheduler
    scheduler = torch.optim.lr_scheduler.OneCycleLR(opt,
                                                    max_lr=params['learning_rate'],
                                                    steps_per_epoch=int(len(train_dataloader)),
                                                    epochs=params['epochs'],
                                                    anneal_strategy='linear')
    # train and test
    for epoch in range(1, params["epochs"] + 1):
        # train_loop(myModel, train_dataloader, loss_fn, opt, scheduler, epoch)
        test_loop(myModel, test_dataloader, loss_fn)
    # save model
    # torch.save(myModel, '../param/voice_nnf_40_new.pth')
