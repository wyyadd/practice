#ifndef ADDBOOK_H
#define ADDBOOK_H
#include <QDialog>
#include<book.h>

namespace Ui {
class AddBook;
}


class AddBook : public QDialog
{
    Q_OBJECT;
public:
    explicit AddBook(QMap<QString, Book*> *nameMap_,
                     QMap<QString, Book*> *IdMap_,
                     QWidget* parent = nullptr);
    ~AddBook();
private:
    Ui::AddBook* ui;
    QMap<QString, Book*> *nameMap_;
    QMap<QString, Book*> *IdMap_;


private slots:
    void on_pushButton_clicked();

signals:
    void FreshTable();
};

#endif // ADDBOOK_H
