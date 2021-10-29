import torch
from DeepLearning.mnist import mnist
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor

if torch.cuda.is_available():
    device = 'cuda'
else:
    device = 'cpu'
training_data = datasets.MNIST(
    root="dataset",
    train=True,
    download=True,
    transform=ToTensor()
)
train_dataloader = DataLoader(training_data, batch_size=64, shuffle=True)

test_data = datasets.MNIST(
    root="dataset",
    train=False,
    download=True,
    transform=ToTensor()
)
test_dataloader = DataLoader(test_data, batch_size=64, shuffle=True)


def train_loop(model, dataloader, loss_function, optimizer):
    size = len(dataloader.dataset)
    for batch, (images, labels) in enumerate(dataloader):
        images, labels = images.to(device), labels.to(device)
        pred = model(images)
        loss = loss_function(pred, labels)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        if batch % 100 == 0:
            loss, current = loss.item(), batch * len(images)
            print(f"loss: {loss:>7f} [{current:>5d}/{size:>5d}]")


def test_loop(model, dataloader, loss_function):
    model.eval()
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    test_loss, correct = 0, 0
    with torch.no_grad():
        for images, labels in dataloader:
            images, labels = images.to(device), labels.to(device)
            pred = model(images)
            test_loss += loss_function(pred, labels).item()
            correct += (pred.argmax(1) == labels).type(torch.float).sum().item()

    test_loss /= num_batches
    correct /= size
    print(f"Test Error: \n Accuracy: {(100 * correct):>0.1f}%, Avg loss: {test_loss:>8f}\n")


if __name__ == "__main__":
    myModel = mnist.MyCNN().to(device)
    learning_rate = 1e-3
    batch_size = 64
    epochs = 5
    loss_fn = nn.CrossEntropyLoss()
    myOptimizer = torch.optim.Adam(myModel.parameters(), lr=learning_rate)
    for i in range(epochs):
        print(f"Epoch {i + 1}\n-------------------")
        train_loop(myModel, train_dataloader, loss_fn, myOptimizer)
        test_loop(myModel, train_dataloader, loss_fn)
    print("Done!")
    torch.save(myModel, '../param/mnist.pth')
