
#ifndef BOOKDEF_C_

#define BOOKDEF_C_

#include "book.h"
#include <stdbool.h>


#define ADD_NEW_ISSUERS 5 

struct book {
    int bookId;

    char* title;
    char* author;
    int noOfPages;

    bool isTaken;
    int library;

    char** issuedBy;
    int maxSize;
    int filled;
};

#endif 