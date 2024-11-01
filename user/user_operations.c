#include "user.h"
#include "userdef.c"
#include "../book/book_def.c"
#include "../utils/utils.h"
#include <stdlib.h>


bool issueBook(User user, char* password, Book book) {

    // Unauthorized 
    if(checkPassword(user, password) == false){
        printf("Unauthorized access detected\n");
        return false;
    }

    // Book already taken
    if(book->isTaken){
        printf("Book already taken\n");
        return false;
    }

    if(user->numberofBooks == user->maxBooks) {
        // Need to allocate more space
        int newSize = user->maxBooks + ADD_NEW_BLOCKS;

        // Create new vector
        int* booksIssued = (int *) malloc(sizeof(int) * newSize);

        char** newBookTitles = (char **) malloc(sizeof(char *) * newSize);

        int i = 0;
        for( ; i < user->numberofBooks ; i++) {
            booksIssued[i] = user->booksIssued[i];
            newBookTitles[i] = dupstr(user->booksTitles[i]);
            free(user->booksTitles[i]);
        }

        booksIssued[i] = book->bookId;
        newBookTitles[i] = dupstr(book->title);

        free(user->booksIssued);
        free(user->booksTitles);
        user->booksIssued = booksIssued;
        user->booksTitles = newBookTitles;

        user->maxBooks = newSize;
        user->numberofBooks++;

        addUserToBook(book, user->username);
        return true;
    }
    else {
        user->booksIssued[user->numberofBooks] = book->bookId;
        user->booksTitles[user->numberofBooks] = dupstr(book->title);
        user->numberofBooks++;

        addUserToBook(book, user->username);
        return true;
    }

}

bool returnBook(User user,  char* password, Book book) {

    // Unauthorized 
    if(checkPassword(user, password) == false){
        printf("Unauthorized access detected\n");
        return false;
    }

    // Book already taken
    if(book->isTaken == false){
        printf("Book has not been taken\n");
        return false;
    }

    // If same person is not returning
    if(strcmp(book->issuedBy[book->filled - 1], user->username) == false) {
        printf("Same person should return the book\n");
        return false;
    }

    book->isTaken = false; 
    return true;

}



void addUserToBook(Book book, char* username) {
    
     if(book->filled == book->maxSize) {
        // Need to allocate more space
        int newSize = book->maxSize + ADD_NEW_ISSUERS;

        // Create new vector
        char* newBlock = (char *) malloc(sizeof(int) * newSize);

        int i = 0;
        for( ; i < book->maxSize ; i++) {
            newBlock[i] = dupstr(book->issuedBy[i]);
            free(book->issuedBy[i]);
        }

        newBlock[i] = dupstr(username);

        free(book->issuedBy);
        book->issuedBy = newBlock;

        book->maxSize = newSize;
        book->filled++;

        book->isTaken = true;
        return true;
    }
    else {
        book->issuedBy[book->filled] = dupstr(username);
        book->filled++;
        book->isTaken = true; 
        return true;
    }
}