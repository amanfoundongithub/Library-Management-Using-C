#ifndef BOOKS_H_

#define BOOKS_H_

#include <stdbool.h>

typedef struct book* Book;

Book createNewBook(int bookId, char* title, char* author, int noOfPages, int library);

void printBook(Book book);

bool saveBookToDB(Book book);

#endif