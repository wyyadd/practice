#include "returnbook.h"
#include "ui_returnbook.h"
#include <QMessageBox>


ReturnBook::ReturnBook(QMap<QString, Book*> *nameMap_,
                 QMap<QString, Book*> *idMap_,
                 QWidget* parent):
    QDialog(parent),
    ui(new Ui::ReturnBook)
{
    this->nameMap_ = nameMap_;
    this->IdMap_ = idMap_;
    ui->setupUi(this);
}

ReturnBook::~ReturnBook(){
    delete ui;
}

void ReturnBook::on_pushButton_clicked(){
    QString id = ui->lineEdit->text();
    for(auto &i : *IdMap_){
        for(auto &j : i->getRegisterSet()){
            if(j->registerId() == id){
                if(j->rentFlag() != "尚未借出"){
                    QMessageBox::information(NULL, "归还成功", "归还图书成功", QMessageBox::Ok);
                    //更新信息
                    j->setRentFlag("尚未借出");
                    j->setRentId("尚未借出");
                    j->setRentTime("尚未借出");
                    i->setStock(i->stock() + 1);
                    i->setRentNum(i->rentNum() - 1);
                    emit FreshTable();
                }
                else
                    QMessageBox::information(NULL, "归还失败", "该书尚未借出", QMessageBox::Ok);
                return;
            }
        }
    }
    QMessageBox::information(NULL, "归还失败", "登记号错误", QMessageBox::Ok);
}

