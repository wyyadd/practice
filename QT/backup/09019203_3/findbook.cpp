#include "findbook.h"
#include "mainwindow.h"
#include "ui_findbook.h"
#include <QWidget>

Findbook::Findbook(Book *book, QWidget* parent):
    QDialog(parent),
    ui(new Ui::Findbook)
{
    ui->setupUi(this);
    this->book = book;
    ui->label_2->setText("书名:"+book->bookName());
    ui->label_3->setText("Id:"+book->bookId());
    ui->label_4->setText("作者名:"+book->autherName());
    ui->label_5->setText("出版日期:"+book->publishDate());
    ui->label_6->setText("出版社:"+book->publishHouse());
    ui->label_7->setText("库存:"+QString::number(book->stock()));
    ui->label_8->setText("借出数:"+QString::number(book->rentNum()));
}

Findbook::~Findbook(){
    delete ui;
}

