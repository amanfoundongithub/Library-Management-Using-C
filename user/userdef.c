

#ifndef USERDEF_C_

#define USERDEF_C_

#include "user.h"

#define ADD_NEW_BLOCKS 5


struct user {
    char* username;
    char* password;

    char* email;

    int* booksIssued;
    int numberofBooks;
    int maxBooks;
};

#endif 

