#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findbook.h"
#include "addbook.h"
#include "book.h"
#include "returnbook.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReadFile();
    ReadRentFile();
}

MainWindow::~MainWindow(){
    SaveFile();
    SaveRentFile();
    delete ui;
}

//从文件中导入书籍信息到Hash表中
void MainWindow::ReadFile(){
    //绝对路径
//    QFile file("/home/wyyadd/coding/QT/09019203_3/book.txt");
    QFile file("../测试数据/book.txt");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text)){
            qDebug() << "Cannot open file!";
            return;
    }
    QTextStream input(&file);
    QString lineStr;//文件的每一行的字符串
    QStringList lineList; //整行字符串，分割处理为单个字符串，存入到表中
    lineList.clear();//操作前，清空
    //遍历文件
    while(!input.atEnd())
    {
            lineStr = input.readLine(); //读取文件的一行
            lineList = lineStr.split(' '); //去除换行符获取字符串，存放到表中
            //向hashmap中放入book类， 方便索引
            Book* book = new Book();
            book->setBookName(lineList[0]);
            book->setBookId(lineList[1]);
            book->setAutherName(lineList[2]);
            book->setPublishDate(lineList[3]);
            book->setPublishHouse(lineList[4]);
            book->setStock(lineList[5].toInt());
            book->setRentNum(lineList[6].toInt());
            nameMap_.insert(lineList[0],book);
            IdMap_.insert(lineList[1],book);
    }
    file.close();//关闭文件
    ShowTable();
}

//从文件中导入借还书数据
void MainWindow::ReadRentFile(){
//    QFile file("/home/wyyadd/coding/QT/09019203_3/rentbook.txt");
    QFile file("../测试数据/rentbook.txt");
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text)){
            qDebug() << "Cannot open file!";
            return;
    }
    QTextStream input(&file);
    QString lineStr;//文件的每一行的字符串
    QStringList lineList; //整行字符串，分割处理为单个字符串，存入到表中
    lineList.clear();//操作前，清空
    //遍历文件
    for(auto &i : IdMap_){
        QList<RentBookInfomation*> *rentList = new QList<RentBookInfomation*>();

        for(int j = 0; j < (i->stock()+i->rentNum()); ++j){
            RentBookInfomation *temp = new RentBookInfomation();
            lineStr = input.readLine(); //读取文件的一行
            lineList = lineStr.split(' '); //去除换行符获取字符串，存放到表中
            temp->setRegisterId(lineList[0]);
            temp->setBookId(lineList[1]);
            temp->setBookName(lineList[2]);
            temp->setRentFlag(lineList[3]);
            temp->setRentTime(lineList[4]);
            temp->setRentId(lineList[5]);
            rentList->append(temp);
        }
        i->setRegisterSet(*rentList);
        nameMap_.constFind(i->bookName()).value()->setRegisterSet(*rentList);
    }
    file.close();//关闭文件
    ShowRentTable();
}

//将hash表中的数据存到文件中
void MainWindow::SaveFile(){
//    QFile file("/home/wyyadd/coding/QT/09019203_3/book.txt");
    QFile file("../测试数据/book.txt");
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Truncate)){
            qDebug() << "Cannot open file!";
            return;
    }
    QTextStream output(&file);
    for(auto i = IdMap_.begin(); i != IdMap_.end(); ++i){
        output << i.value()->bookName() << ' ' << i.value()->bookId() << ' '  << i.value()->autherName()
               << ' '  << i.value()->publishDate()  << ' ' << i.value()->publishHouse()
               << ' ' << i.value()->stock()  << ' ' << i.value()->rentNum() << "\n";
    }
    file.close();
}

//将借还书数据存到文件中
void MainWindow::SaveRentFile(){
//    QFile file("/home/wyyadd/coding/QT/09019203_3/rentbook.txt");
    QFile file("../测试数据/rentbook.txt");
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Truncate)){
            qDebug() << "Cannot open file!";
            return;
    }
    QTextStream output(&file);
    for(auto i = IdMap_.begin(); i != IdMap_.end(); ++i){
        for(auto &j : i.value()->getRegisterSet()){
            output << j->registerId() << ' ' << j->bookId()<< ' '
                   << j->bookName() << ' ' << j->rentFlag() << ' '
                   <<j->getRentTime() << ' ' << j->rentId() << '\n';
        }
    }
    file.close();
}

//刷新并重新显示表格
void MainWindow::ShowTable(){
    //设置表头显示模式,这里设置的是拉伸模式
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //清空table中内容
    for(int i = ui->tableWidget->rowCount() - 1; i >= 0; --i)
        ui->tableWidget->removeRow(i);
    //从hash表中添加
    for(auto i = nameMap_.begin(); i != nameMap_.end(); ++i)
    {
        int num = 0;
        //向表里面动态添加参数
        int rowCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowCount);
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(i.value()->bookName()));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(i.value()->bookId()));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(i.value()->autherName()));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(i.value()->publishDate()));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(i.value()->publishHouse()));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(QString::number(i.value()->stock())));
        ui->tableWidget->setItem(rowCount,num++,new QTableWidgetItem(QString::number(i.value()->rentNum())));
    }
}

//刷新并重新展示借还书表格
void MainWindow::ShowRentTable(){
    //设置表头显示模式,这里设置的是拉伸模式
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //清空table中内容
    for(int i = ui->tableWidget_2->rowCount() - 1; i >= 0; --i)
        ui->tableWidget_2->removeRow(i);
    for(auto &i : IdMap_){
        for(auto &j : i->getRegisterSet()){
            int num = 0;
            //向表里面动态添加参数
            int rowCount = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowCount);
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->registerId()));
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->bookId()));
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->bookName()));
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->rentFlag()));
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->getRentTime()));
            ui->tableWidget_2->setItem(rowCount,num++,new QTableWidgetItem(j->rentId()));
        }
    }
}

//接收刷新信号
void MainWindow::receiveFreshTable(){
    ShowTable();
    ShowRentTable();
}

//添加图书
void MainWindow::on_pushButton_6_clicked(){
    AddBook *addbook = new AddBook(&nameMap_, &IdMap_);
    connect(addbook,SIGNAL(FreshTable()),this,SLOT(receiveFreshTable()));
    addbook->exec();
    delete addbook;
}

//根据书名查找图书
void MainWindow::on_pushButton_2_clicked(){
    QString query = ui->lineEdit->text();
    if(nameMap_.find(query) != nameMap_.end()){
        Findbook *fb = new Findbook(nameMap_.find(query).value());
        fb->exec();
        delete fb;
    }
    else{
        QMessageBox::information(NULL, "查找失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//根据书Id查找图书
void MainWindow::on_pushButton_clicked(){
    QString query = ui->lineEdit_5->text();
    if(IdMap_.find(query) != IdMap_.end()){
        Findbook *fb = new Findbook(IdMap_.find(query).value());
        fb->exec();
        delete fb;
    }
    else{
        QMessageBox::information(NULL, "查找失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//通过书名删除书籍
void MainWindow::on_pushButton_5_clicked(){
    QString query = ui->lineEdit->text();
    auto it = nameMap_.constFind(query);
    if(it != nameMap_.constEnd()){
        //nameMap和idmap同时删除      
        IdMap_.erase(IdMap_.constFind(it.value()->bookId()));
        nameMap_.erase(it);
        QMessageBox::information(NULL, "删除成功", "成功删除书籍", QMessageBox::Yes);
        ShowTable();
        ShowRentTable();
    }
    else{
        QMessageBox::information(NULL, "删除失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//通过书id删除书籍
void MainWindow::on_pushButton_7_clicked(){
    QString query = ui->lineEdit_5->text();
    auto it = IdMap_.constFind(query);
    if(it != IdMap_.constEnd()){
        //nameMap和idmap同时删除
        nameMap_.erase(nameMap_.constFind(it.value()->bookName()));
        IdMap_.erase(it);
        QMessageBox::information(NULL, "删除成功", "成功删除书籍", QMessageBox::Yes);
        ShowTable();
        ShowRentTable();
    }
    else{
        QMessageBox::information(NULL, "删除失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//通过书名查询借阅信息
void MainWindow::on_pushButton_3_clicked(){
    QString query = ui->lineEdit_2->text();
    auto it = nameMap_.constFind(query);
    if(it != nameMap_.constEnd()){
        if(it.value()->stock() > 0){
            QMessageBox::information(NULL, "查找成功", query+"的库存为:"
                                    +QString::number(it.value()->stock())+"\n可以借阅", QMessageBox::Yes);
        }
        else{
            QMessageBox::information(NULL, "查找成功", query+"的库存为0"
                                    +"\n不可以借阅", QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::information(NULL, "查找失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//通过书id查询借阅信息
void MainWindow::on_pushButton_4_clicked(){
    QString query = ui->lineEdit_6->text();
    auto it = IdMap_.constFind(query);
    if(it != IdMap_.constEnd()){
        if(it.value()->stock() > 0){
            QMessageBox::information(NULL, "查找成功", query+"的库存为:"
                                    +QString::number(it.value()->stock())+"\n可以借阅", QMessageBox::Yes);
        }
        else{
            QMessageBox::information(NULL, "查找成功", query+"的库存为0"
                                    +"\n不可以借阅", QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::information(NULL, "查找失败", "找不到相关书籍，请重试", QMessageBox::Yes);
    }
}

//通过书名借书
void MainWindow::on_pushButton_9_clicked(){
    QString query = ui->lineEdit_2->text();
    auto it = nameMap_.constFind(query);
    if(it != nameMap_.constEnd()){
        if(it.value()->stock() > 0){
            //更新借书日期，是否借出和借书id
            it.value()->getRegisterSet()[it.value()->rentNum()]->setRentFlag("已借出");
            it.value()->getRegisterSet()[it.value()->rentNum()]
                    ->setRentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
            //为了方便，将借书id设置为与登记号相同
            it.value()->getRegisterSet()[it.value()->rentNum()]
                    ->setRentId(it.value()->getRegisterSet()[it.value()->rentNum()]->registerId());
            QMessageBox::information(NULL, "借阅成功","借书成功\n你的登记号为:"
                                    +it.value()->getRegisterSet()[it.value()->rentNum()]->registerId()
                                    , QMessageBox::Ok);
            //更新库存和借书数量
            it.value()->setStock(it.value()->stock() - 1);
            it.value()->setRentNum(it.value()->rentNum() + 1);
            //重新展示表格
            ShowTable();
            ShowRentTable();
        }
        else{
            QMessageBox::information(NULL, "借书", query+"的库存为0"
                                    +"\n不可以借阅", QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::information(NULL, "借书失败", "找不到相关书籍，请重试", QMessageBox::Ok);
    }
}

//通过书id借书
void MainWindow::on_pushButton_11_clicked(){
    QString query = ui->lineEdit_6->text();
    auto it = IdMap_.constFind(query);
    if(it != IdMap_.constEnd()){
        if(it.value()->stock() > 0){
            //更新借书日期，是否借出和借书id
            it.value()->getRegisterSet()[it.value()->rentNum()]->setRentFlag("已借出");
            it.value()->getRegisterSet()[it.value()->rentNum()]
                    ->setRentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
            //为了方便，将借书id设置为与登记号相同
            it.value()->getRegisterSet()[it.value()->rentNum()]
                    ->setRentId(it.value()->getRegisterSet()[it.value()->rentNum()]->registerId());
            QMessageBox::information(NULL, "借阅成功","借书成功\n你的登记号为:"
                                    +it.value()->getRegisterSet()[it.value()->rentNum()]->registerId()
                                    , QMessageBox::Ok);
            //更新库存和借书数量
            it.value()->setStock(it.value()->stock() - 1);
            it.value()->setRentNum(it.value()->rentNum() + 1);
            //重新展示表格
            ShowTable();
            ShowRentTable();
        }
        else{
            QMessageBox::information(NULL, "借书", query+"的库存为0"
                                    +"\n不可以借阅", QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::information(NULL, "借书失败", "找不到相关书籍，请重试", QMessageBox::Ok);
    }
}

//通过登记号还书
void MainWindow::on_pushButton_10_clicked(){
    ReturnBook* returnBook = new ReturnBook(&nameMap_, &IdMap_);
    connect(returnBook,SIGNAL(FreshTable()),this,SLOT(receiveFreshTable()));
    returnBook->exec();
    delete returnBook;
}
