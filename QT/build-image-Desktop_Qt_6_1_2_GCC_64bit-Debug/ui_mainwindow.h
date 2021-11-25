/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_8;
    QWidget *tab_2;
    QGraphicsView *graphicsView_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1229, 786);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1231, 791));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1070, 210, 89, 31));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1070, 90, 91, 31));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1060, 150, 113, 25));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(false);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 710, 101, 41));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1060, 180, 113, 25));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(1060, 270, 111, 31));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setClearButtonEnabled(false);
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(770, 710, 101, 41));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1070, 310, 89, 31));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 1041, 691));
        graphicsView->setAutoFillBackground(true);
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 710, 91, 41));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1060, 50, 113, 25));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1060, 20, 113, 25));
        lineEdit->setAlignment(Qt::AlignCenter);
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 710, 101, 41));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(1060, 380, 113, 25));
        lineEdit_6->setAlignment(Qt::AlignCenter);
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(1060, 410, 113, 25));
        lineEdit_7->setAlignment(Qt::AlignCenter);
        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(1070, 440, 89, 25));
        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(1060, 510, 111, 31));
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(1060, 540, 113, 25));
        lineEdit_8->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        graphicsView_2 = new QGraphicsView(tab_2);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(60, 10, 881, 591));
        graphicsView_2->setAutoFillBackground(true);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206\345\256\236\351\252\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\347\274\251\346\224\276", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\345\271\263\347\247\273", nullptr));
        lineEdit_3->setInputMask(QString());
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\253\226\347\233\264\347\274\251\346\224\276", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200BMP\345\233\276\345\203\217", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\347\274\251\346\224\276", nullptr));
        lineEdit_5->setInputMask(QString());
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\210\345\272\246\357\274\211", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\345\233\276\345\203\217", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\347\247\273\345\212\250\350\267\235\347\246\273", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\253\226\347\233\264\347\247\273\345\212\250\350\267\235\347\246\273", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200raw\345\233\276\345\203\217", nullptr));
        lineEdit_6->setInputMask(QString());
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\215", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\252\227\345\256\275", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\346\230\240\345\260\204", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\347\273\206\350\212\202\345\242\236\345\274\272", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "alpha(defalt=1)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "LAB1,2,3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "LAB4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
