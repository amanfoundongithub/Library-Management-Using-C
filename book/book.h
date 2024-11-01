#ifndef BOOKS_H_

#define BOOKS_H_

#include <stdbool.h>

typedef struct book* Book;

Book createNewBook(int bookId, char* title, int noOfPages, int library);

bool getIsTaken(Book book);

void setIsTaken(Book book, bool isTaken);

int getBookID(Book book);

#endif