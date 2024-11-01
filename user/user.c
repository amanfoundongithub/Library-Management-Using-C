#include "user.h"
#include "userdef.c"
#include "../utils/utils.h"

#include <stdlib.h>

User createUser(char* email, char* password, char* username) {
    // Allocate memory to the user
    User newUser = (User) malloc(sizeof(struct user));
    // Set email
    newUser->email = dupstr(email);
    // Set password
    newUser->password = dupstr(password);
    // Set username
    newUser->username = dupstr(username);

    newUser->booksIssued = malloc(sizeof(int) * ADD_NEW_BLOCKS);
    newUser->numberofBooks = 0;
    newUser->maxBooks = ADD_NEW_BLOCKS;

    newUser->booksTitles = malloc(sizeof(char *) * ADD_NEW_BLOCKS);

    return newUser;
}

char* getEmail(User user) {
    return user->email;
}

char* getUsername(User user) {
    return user->username;
}

bool checkPassword(User user, char* password) {
    return strcmp(user->password, password);
}

