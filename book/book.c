#include "book.h"
#include <stdlib.h>
#include "book_def.c"
#include "../utils/utils.h"

Book createNewBook(int bookId, char* title, int noOfPages, int library) {

    Book newBook = (Book) malloc(sizeof(struct book));

    newBook->bookId = bookId;
    newBook->isTaken = false;
    newBook->library = library;

    newBook->noOfPages = noOfPages;
    newBook->title = dupstr(title);

    newBook->issuedBy = NULL;

    return newBook;
}

bool getIsTaken(Book book) {
    return book->isTaken;
}

int getBookID(Book book) {
    return book->bookId;
}

void setIsTaken(Book book, bool isTaken) {
    book->isTaken = isTaken;
}