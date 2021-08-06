#include "addbook.h"
#include <QMessageBox>
#include "ui_addbook.h"


AddBook::AddBook(QMap<QString, Book*> *nameMap_,
                 QMap<QString, Book*> *idMap_,
                 QWidget* parent):
    QDialog(parent),
    ui(new Ui::AddBook)
{
    this->nameMap_ = nameMap_;
    this->IdMap_ = idMap_;
    ui->setupUi(this);
}

AddBook::~AddBook(){
    delete ui;
}

void AddBook::on_pushButton_clicked(){
    //如果书名和Id同时不存在才添加
    if(nameMap_->find(ui->lineEdit->text()) == nameMap_->end() &&
            IdMap_->find(ui->lineEdit_2->text()) == IdMap_->end()){
        Book *bk = new Book();
        bk->setBookName(ui->lineEdit->text());
        bk->setBookId(ui->lineEdit_2->text());
        bk->setAutherName(ui->lineEdit_3->text());
        bk->setPublishDate(ui->lineEdit_4->text());
        bk->setPublishHouse(ui->lineEdit_5->text());
        bk->setStock(ui->spinBox->text().toInt());
        bk->setRentNum(0);

        //存登记号数据集
        QList<RentBookInfomation*> *rentBookList = new QList<RentBookInfomation*>;
        for(int i = 0; i < bk->stock(); ++i){
            RentBookInfomation *temp = new RentBookInfomation();
            temp->setBookName(bk->bookName());
            temp->setBookId(bk->bookId());
            //登记号命名模式为书名+number
            temp->setRegisterId(bk->bookName() + QString::number(i));
            rentBookList->append(temp);
        }
        bk->setRegisterSet(*rentBookList);
        //同时向两个hashmap中存
        nameMap_->insert(bk->bookName(), bk);
        IdMap_->insert(bk->bookId(), bk);
        QMessageBox::information(NULL, "添加成功", "添加图书成功", QMessageBox::Yes);     
        emit FreshTable();
    }
    else{
        QMessageBox::information(NULL, "添加失败", "已存在书籍，请重试", QMessageBox::Yes);
    }
}


