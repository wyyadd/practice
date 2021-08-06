#ifndef FINDBOOK_H
#define FINDBOOK_H
#include <QDialog>
#include "book.h"
namespace Ui {
class Findbook;
}
class Findbook : public QDialog
{
    Q_OBJECT;
public:
    explicit Findbook(Book *book, QWidget* parent = nullptr);
    ~Findbook();
private:
    Ui::Findbook *ui;
    Book *book;
};

#endif // FINDBOOK_H
