
#ifndef BOOKDEF_C_

#define BOOKDEF_C_

#include "book.h"
#include <stdbool.h>


struct book {
    int bookId;

    char* title;
    int noOfPages;

    bool isTaken;
    int library;

    int* issuedBy;
};

#endif 