#include "user.h"
#include "userdef.c"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>


char* filePath(const char* username) {
    return strcat("./db/user/", username);
}

FILE* openUserFile(const char* username, const char* mode) {

    char* path = filePath(username);
    char* path2 = strcat(path, ".txt");
    free(path);
    FILE* fp = fopen(path2, mode);
    free(path2);
    return fp; 
}


bool saveUserToDB(const User user) {

    // Open the file
    FILE* f = openUserFile(user->username, "w");

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

User retrieveUserfromDB(const char* username) {

    // Open the file
    FILE* f = openUserFile(username, "r");

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
    fscanf(f, "%d\n%d\n", &(user->maxBooks), &(user->numberofBooks));

    user->booksIssued = (int *) malloc(sizeof(int) * user->maxBooks);
    user->booksTitles = (char *) malloc(sizeof(char *) * user->maxBooks)
    ;
    // Get book details
    for(int i = 0 ; i < user->numberofBooks;  i++){
        char* bookTitle = (char *) malloc(sizeof(char) * 40);
        fscanf(f, "%d\n",&(user->booksIssued[i]));
        if(fgets(bookTitle, 40 , f)) {
            int len = strlen(bookTitle);
            if(len > 0 && bookTitle[len -  1] == '\n'){
                bookTitle[len - 1] = '\0';
            }
        }
        user->booksTitles[i] = dupstr(bookTitle);
        free(bookTitle);
    }

    fclose(f);
    return user;

}

bool deleteUserFromDB(const User user) {

    // Open file
    char* file = filePath(user->username);

    // Get username
    char* username = dupstr(user->username);

    // remove file 
    if(remove(file) == 0) {
        printf("User %s has been deleted from DB!\n", username);
        free(file);
        free(username);
        return true;
    }
    else {
        printf("Error in deleting User %s\n", username);
        free(file);
        free(username);
        return false;
    }
}

bool updateUserInDB(const User user) { 
    return saveUserToDB(user);
}


