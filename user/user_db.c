#include "user.h"
#include "userdef.c"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>


bool saveToDB(User user) {
    // Open the file

    
    FILE* f = fopen(strcat(strcat("./db/user/", user->username), ".txt"), "w");

    // Save details first 
    fprintf(f, "%s\n%s\n%s\n", user->username, user->password, user->email);

    // Save number details 
    fprintf(f, "%d\n%d\n", user->maxBooks, user->numberofBooks);

    // Save book details
    for(int i = 0 ; i < user->numberofBooks;  i++){
        fprintf(f, "%d\n%s\n",user->booksIssued[i], user->booksTitles[i]);
    }

    fclose(f);
    return true;
}

User retrievefromDB(char* username) {

    // Open the file
    FILE* f = fopen(strcat(strcat("./db/user/", username), ".txt"), "r");

    if(f == NULL){
        printf("Cannot read details of %s\n", username);
        return NULL;
    }


    User user = (User) malloc(sizeof(struct user));

    user->username = malloc(sizeof(char) * 30);
    user->email = malloc(sizeof(char)*30);
    user->password = malloc(sizeof(char)* 30);

    fscanf(f, "%s\n%s\n%s\n", user->username, user->password, user->email);

    char* newstr = dupstr(user->username);
    free(user->username);
    user->username = newstr;

    char* newstr2 = dupstr(user->email);
    free(user->email);
    user->email = newstr2;

    char* newstr3 = dupstr(user->password);
    free(user->password);
    user->password = newstr3;

    // Get number details 
    fscanf(f, "%d\n%d\n", &user->maxBooks, &user->numberofBooks);

    user->booksIssued = (int *) malloc(sizeof(int) * user->maxBooks);

    // Get book details
    for(int i = 0 ; i < user->numberofBooks;  i++){
        char* bookTitle = (char *) malloc(sizeof(char) * 40);
        fscanf(f, "%d\n%s\n",&user->booksIssued[i], bookTitle);
        user->booksTitles[i] = dupstr(bookTitle);
        free(bookTitle);
    }

    fclose(f);
    return user;

}