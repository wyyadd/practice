#ifndef BOOKLIBRARY_H
#define BOOKLIBRARY_H

#include<book.h>
class BookLibrary
{
public:
    BookLibrary();
private:
    QList<Book> bookLibrary_;
};

#endif // BOOKLIBRARY_H
