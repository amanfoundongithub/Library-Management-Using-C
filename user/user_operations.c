#include "user.h"
#include "userdef.c"
#include "../book/book.h"
#include <stdlib.h>


bool issueBook(User user, char* password, Book book) {

    // Unauthorized 
    if(checkPassword(user, password) == false){
        printf("Unauthorized access detected\n");
        return false;
    }

    // Book already taken
    if(getIsTaken(book)){
        printf("Book already taken\n");
        return false;
    }

    if(user->numberofBooks == user->maxBooks) {
        // Need to allocate more space
        int newSize = user->maxBooks + ADD_NEW_BLOCKS;

        // Create new vector
        int* booksIssued = (int *) malloc(sizeof(int) * newSize);

        int i = 0;
        for( ; i < user->numberofBooks ; i++) {
            booksIssued[i] = user->booksIssued[i];
        }

        booksIssued[i] = getBookID(book);

        free(user->booksIssued);
        user->booksIssued = booksIssued;

        user->maxBooks = newSize;
        user->numberofBooks++;

        setIsTaken(book, true);
        return true;
    }
    else {
        user->booksIssued[user->numberofBooks] = getBookID(book);

        user->numberofBooks++;
        setIsTaken(book, true);

        return true;
    }

    
}