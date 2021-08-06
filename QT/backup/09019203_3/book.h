#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QDateTime>
#include <rentbookinfomation.h>
class Book
{
public:
    Book();

    const QString &bookName() const;
    void setBookName(const QString &newBookName);
    const QString &bookId() const;
    void setBookId(const QString &newBookId);
    const QString &autherName() const;
    void setAutherName(const QString &newAutherName);
    const QString &publishDate() const;
    void setPublishDate(const QString &newPublishDate);
    const QString &publishHouse() const;
    void setPublishHouse(const QString &newPublishHouse);
    int stock() const;
    void setStock(int newStock);
    int rentNum() const;
    void setRentNum(int newRentNum);
    const QList<RentBookInfomation*> &getRegisterSet() const;
    void setRegisterSet(const QList<RentBookInfomation*> &newRegisterSet);

private:
    QString bookName_;  //书名
    QString bookId_;    //书id
    QString autherName_; //作者名
    QString publishDate_;//出版日期
    QString publishHouse_;//出版社
    int stock_; //库存
    int rentNum_; //借出书籍数量
    QList<RentBookInfomation*> registerSet; //登记号数据集

};

#endif // BOOK_H
