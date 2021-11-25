#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets>
#include<book.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadFile();//从文件中导入书籍信息到Hash表中
    void ReadRentFile(); //从文件中导入借还书数据
    void SaveFile();//将hash表中的数据存到文件中
    void SaveRentFile();//将借还书数据存到文件中
    void ShowTable(); //刷新并重新展示表格
    void ShowRentTable(); //刷新并重新展示借还书表格
private:
    Ui::MainWindow *ui;
    QMap<QString, Book*> nameMap_;
    QMap<QString, Book*> IdMap_;

private slots:
    void receiveFreshTable(); //接收刷新表格的信号
    void on_pushButton_6_clicked();//增加书籍
    void on_pushButton_2_clicked();//通过书名查询书籍
    void on_pushButton_clicked(); //通过书id查询书籍
    void on_pushButton_5_clicked(); //通过书名删除书籍
    void on_pushButton_7_clicked(); //通过书id删除书籍
    void on_pushButton_3_clicked(); //通过书名查询借阅信息
    void on_pushButton_4_clicked(); //通过书id查询借阅信息
    void on_pushButton_9_clicked(); //通过书名借书
    void on_pushButton_11_clicked();//通过书id借书
    void on_pushButton_10_clicked(); //通过登记号还书
};

#endif // MAINWINDOW_H
