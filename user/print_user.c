#include "user.h"
#include "userdef.c"
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

void printUser(User user) {
    printf("User Details:\n");
    printf("\t" GREEN  "Username: %s\n" RESET, user->username);
    printf("\t" YELLOW "Email: %s\n" RESET, user->email);

    printf("\t" CYAN "Books issued:\n" RESET);
    for(int i = 0 ; i < user->numberofBooks ; i++){
        printf("\t\tBook Title: %s\tBook ID: %d\n", user->booksTitles[i], user->booksIssued[i]);
    }
}
