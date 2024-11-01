
#ifndef USER_H_
#define USER_H_
#include <stdbool.h>
#include "../book/book.h"

typedef struct user* User; 

User createUser(char* email, char* password, char* username);

char* getEmail(User user);
char* getUsername(User user);

bool checkPassword(User user, char* password);

void printUser(User user);

bool issueBook(User user, char* password, Book book);

bool returnBook(User user, char* password, Book book);

bool saveToDB(User user);
User retrievefromDB(char* username);


#endif
