#include "book.h"
#include <stdlib.h>
#include "book_def.c"
#include "../utils/utils.h"

Book createNewBook(int bookId, char* title, char* author, int noOfPages, int library) {

    Book newBook = (Book) malloc(sizeof(struct book));

    newBook->bookId = bookId;
    newBook->isTaken = false;
    newBook->library = library;

    newBook->noOfPages = noOfPages;
    newBook->title = dupstr(title);
    newBook->author = dupstr(author);

    newBook->issuedBy = malloc(sizeof(char *) * ADD_NEW_ISSUERS);
    newBook->maxSize = ADD_NEW_ISSUERS;
    newBook->filled = 0;

    return newBook;
}

