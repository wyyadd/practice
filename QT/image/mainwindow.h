#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <myimage.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void ShowImage(); //展示图像
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QString ImageAddress; //图片地址
    MyImage *image = nullptr; //我的图像类

private slots:
   void on_pushButton_clicked(); //打开图像文件
   void on_pushButton_2_clicked(); //保存图像文件
   void on_pushButton_3_clicked(); //重置图像
   void on_pushButton_4_clicked(); //缩放图像
   void on_pushButton_5_clicked(); //旋转图像
   void on_pushButton_6_clicked(); //平移图像
   void on_pushButton_7_clicked(); //打开raw图像
   void on_pushButton_8_clicked(); //灰度窗映射
   void on_pushButton_9_clicked(); //细节增强

};
#endif // MAINWINDOW_H
