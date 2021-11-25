#include "book.h"

Book::Book()
{

}

const QString &Book::bookName() const
{
    return bookName_;
}

void Book::setBookName(const QString &newBookName)
{
    bookName_ = newBookName;
}

const QString &Book::bookId() const
{
    return bookId_;
}

void Book::setBookId(const QString &newBookId)
{
    bookId_ = newBookId;
}

const QString &Book::autherName() const
{
    return autherName_;
}

void Book::setAutherName(const QString &newAutherName)
{
    autherName_ = newAutherName;
}

const QString &Book::publishDate() const
{
    return publishDate_;
}

void Book::setPublishDate(const QString &newPublishDate)
{
    publishDate_ = newPublishDate;
}

const QString &Book::publishHouse() const
{
    return publishHouse_;
}

void Book::setPublishHouse(const QString &newPublishHouse)
{
    publishHouse_ = newPublishHouse;
}

int Book::stock() const
{
    return stock_;
}

void Book::setStock(int newStock)
{
    stock_ = newStock;
}

int Book::rentNum() const
{
    return rentNum_;
}


void Book::setRentNum(int newRentNum)
{
    rentNum_ = newRentNum;
}


const QList<RentBookInfomation*> &Book::getRegisterSet() const
{
    return registerSet;
}

void Book::setRegisterSet(const QList<RentBookInfomation*> &newRegisterSet)
{
    registerSet = newRegisterSet;
}
