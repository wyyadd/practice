#include "rentbookinfomation.h"

RentBookInfomation::RentBookInfomation()
{
}

const QString &RentBookInfomation::registerId() const
{
    return registerId_;
}

void RentBookInfomation::setRegisterId(const QString &newRegisterId)
{
    registerId_ = newRegisterId;
}

const QString &RentBookInfomation::bookId() const
{
    return bookId_;
}

void RentBookInfomation::setBookId(const QString &newBookId)
{
    bookId_ = newBookId;
}

const QString &RentBookInfomation::bookName() const
{
    return bookName_;
}

void RentBookInfomation::setBookName(const QString &newBookName)
{
    bookName_ = newBookName;
}

const QString &RentBookInfomation::rentFlag() const
{
    return rentFlag_;
}

void RentBookInfomation::setRentFlag(const QString &newRentFlag)
{
    rentFlag_ = newRentFlag;
}

const QString &RentBookInfomation::getRentTime() const
{
    return rentTime;
}

void RentBookInfomation::setRentTime(const QString &newRentTime)
{
    rentTime = newRentTime;
}

const QString &RentBookInfomation::rentId() const
{
    return rentId_;
}

void RentBookInfomation::setRentId(const QString &newRentId)
{
    rentId_ = newRentId;
}
