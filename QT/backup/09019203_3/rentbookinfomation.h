#ifndef RENTBOOKINFOMATION_H
#define RENTBOOKINFOMATION_H

#include <QDateTime>

class RentBookInfomation
{
public:
    RentBookInfomation();



    const QString &registerId() const;
    void setRegisterId(const QString &newRegisterId);
    const QString &bookId() const;
    void setBookId(const QString &newBookId);
    const QString &bookName() const;
    void setBookName(const QString &newBookName);
    const QString &rentFlag() const;
    void setRentFlag(const QString &newRentFlag);
    const QString &getRentTime() const;
    void setRentTime(const QString &newRentTime);
    const QString &rentId() const;
    void setRentId(const QString &newRentId);

private:
    QString registerId_; //登记号
    QString bookId_; //书籍Id
    QString bookName_; //书名
    //是否借出
    QString rentFlag_ = "尚未借出";
    //借出时间
    QString rentTime = "尚未借出";
    //借书证号
    QString rentId_ = "尚未借出";
};

#endif // RENTBOOKINFOMATION_H
