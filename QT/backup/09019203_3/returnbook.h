#ifndef RETURNBOOK_H
#define RETURNBOOK_H
#include <QDialog>
#include <book.h>

namespace Ui {
class ReturnBook;
}


class ReturnBook : public QDialog
{
    Q_OBJECT;
public:
    explicit ReturnBook(QMap<QString, Book*> *nameMap_,
                     QMap<QString, Book*> *IdMap_,
                     QWidget* parent = nullptr);
    ~ReturnBook();
private:
    Ui::ReturnBook* ui;
    QMap<QString, Book*> *nameMap_;
    QMap<QString, Book*> *IdMap_;
private slots:
    void on_pushButton_clicked();

signals:
    void FreshTable();
};

#endif // RETURNBOOK_H
