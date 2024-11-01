#include "book.h"
#include "book_def.c"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>


bool saveBookToDB(Book book) {
    // Open the file
    FILE* f = fopen(strcat(strcat("./db/book/", numTostr(book->bookId)), ".txt"), "w");

    // Save details first 
    fprintf(f, "%s\n%s\n%d\n%d\n", book->author, book->title, book->bookId, book->noOfPages);

    // Save number details 
    fprintf(f, "%d\n%d\n%d\n%d\n", book->maxSize, book->filled, book->isTaken, book->library);

    // Save book details
    for(int i = 0 ; i < book->filled;  i++){
        fprintf(f, "%s\n",book->issuedBy[i]);
    }

    fclose(f);
    return true;
}



