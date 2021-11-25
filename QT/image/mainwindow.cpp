#include"mainwindow.h"
#include "ui_mainwindow.h"
#include "myimage.h"


#include <QImage>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

//展示图片
void MainWindow::ShowImage(){
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(image->getImageData())));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete image;
    delete scene;
}

//打开BMP图像文件
void MainWindow::on_pushButton_clicked(){
    //删除之前的
    if(image != nullptr)
        delete image;
    ImageAddress = QFileDialog::getOpenFileName
            (this,tr("Open Image"), "/home/wyyadd", tr("Image Files (*.bmp *.BMP)"));
    if(!ImageAddress.isNull()){
        image = new MyImage(QImage(ImageAddress));
        ShowImage();
    }
    else{
        ui->graphicsView->scene()->clear();
        image = nullptr;
    }
}

//打开raw图像
void MainWindow::on_pushButton_7_clicked(){
    //删除之前的
    if(image != nullptr)
        delete image;
    ImageAddress = QFileDialog::getOpenFileName
            (this,tr("Open Image"), "/home/wyyadd", tr("Image Files (*.raw)"));
    if(!ImageAddress.isNull()){
        image = new MyImage(ImageAddress);
    }
    else{
        image = nullptr;
    }
    ui->graphicsView->scene()->clear();
}

//保存图像文件
void MainWindow::on_pushButton_2_clicked(){
    if(image != nullptr){
        QString saveDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                            "/home",
                                                            QFileDialog::ShowDirsOnly
                                                            | QFileDialog::DontResolveSymlinks);
        if(image->getImageData().save(saveDir+"/newImage.bmp")){
            QMessageBox::information(NULL, "成功", "保存图片成功", QMessageBox::Yes);
        }
        else {
            QMessageBox::information(NULL, "失败", "保存图片失败", QMessageBox::Yes);
        }
    }else {
        QMessageBox::information(NULL, "失败", "未指定图片", QMessageBox::Yes);
    }
}

//重置图像
void MainWindow::on_pushButton_3_clicked(){
    if(image != nullptr && (image->type == "raw0" || image->type == "raw1")){
        QMessageBox::information(NULL, "失败", "raw图像请点击映射重置", QMessageBox::Yes);
        return;
    }
    //删除之前的
    if(image != nullptr)
        delete image;
    if(!ImageAddress.isNull() && ImageAddress.length() != 0){
        image = new MyImage(QImage(ImageAddress));
        ShowImage();
    }
}

//缩放图像
void MainWindow::on_pushButton_4_clicked(){
    if(image == nullptr){
        QMessageBox::information(NULL, "失败", "未指定图片", QMessageBox::Yes);
        return;
    }
    if(image->type == "raw0"){
        QMessageBox::information(NULL, "失败", "请先映射", QMessageBox::Yes);
        return;
    }
    double x = ui->lineEdit_3->text().toDouble();
    double y = ui->lineEdit_4->text().toDouble();
    if(x <= 0 || y <= 0){
        QMessageBox::information(NULL, "失败", "缩放比例必须为正数", QMessageBox::Yes);
        return;
    }
    image->Scaling(x,y);
    ShowImage();
}

//旋转图像
void MainWindow::on_pushButton_5_clicked(){
    if(image == nullptr){
        QMessageBox::information(NULL, "失败", "未指定图片", QMessageBox::Yes);
        return;
    }
    if(image->type == "raw0"){
        QMessageBox::information(NULL, "失败", "请先映射", QMessageBox::Yes);
        return;
    }
    double pi = 3.1415926;
    double m = ui->lineEdit_5->text().toDouble();
    image->Rotation(m*pi/180);
    ShowImage();
}


//平移图像
void MainWindow::on_pushButton_6_clicked(){
    if(image == nullptr){
        QMessageBox::information(NULL, "失败", "未指定图片", QMessageBox::Yes);
        return;
    }
    if(image->type == "raw0"){
        QMessageBox::information(NULL, "失败", "请先映射", QMessageBox::Yes);
        return;
    }
    int x = ui->lineEdit->text().toDouble();
    int y = ui->lineEdit_2->text().toDouble();
    image->Translation((int)x,(int)y);
    ShowImage();
}

//灰度窗
void MainWindow::on_pushButton_8_clicked(){
    if(image == nullptr){
        QMessageBox::information(NULL, "失败", "未指定RAW图片", QMessageBox::Yes);
        return;
    }
   long pos = ui->lineEdit_6->text().toLong();
   long width= ui->lineEdit_7->text().toLong();
   if(pos <= 0 || width <= 0){
        QMessageBox::information(NULL, "失败", "参数必须为正数", QMessageBox::Yes);
        return;
   }
   if(image->windowsMapping(pos,width))
     ShowImage();
   else
    QMessageBox::information(NULL, "失败", "请检查参数是否正确", QMessageBox::Yes);
}

//细节增强
void MainWindow::on_pushButton_9_clicked(){
    if(image == nullptr){
        QMessageBox::information(NULL, "失败", "未指定图片", QMessageBox::Yes);
        return;
    }
    if(image->type == "raw0"){
        QMessageBox::information(NULL, "失败", "请先映射", QMessageBox::Yes);
        return;
    }
    double alpha = ui->lineEdit_8->text().toDouble();
    if(alpha == 0) alpha = 1;
    image->GaussianFilter();
    image->UnsharpMasking(alpha);
    ShowImage();
}



