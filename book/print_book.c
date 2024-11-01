#include "book.h"
#include "book_def.c"
#include "../utils/utils.h"
#include <stdio.h>


// ANSI color codes
#define RESET       "\x1b[0m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"

void printBook(Book book) {
    printf("Book Details:\n");
    printf("\t" GREEN  "Name of Book: %s\n" RESET, book->title);
    printf("\t" YELLOW "Author: %s\n" RESET, book->author);

    printf("\t" RED "Number of pages : %d\n" RESET, book->noOfPages);

    printf("\tStatus: %s\n", book->isTaken == false ? GREEN "Available" : RED "Not Available");

    printf("\t" CYAN "Issue History:\n" RESET);
    for(int i = 0 ; i < book->filled ; i++){
        printf("\t\tIssuer #%d: %s\n", book->filled - i, book->issuedBy[i]);
    }


}
