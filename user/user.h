
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


/**********************************************************
 * Database operations (CRUD) 
 **********************************************************/
// Create User
bool saveUserToDB(const User user);
// Read User
User retrieveUserfromDB(const char* username);
// Updates User 
bool updateUserInDB(const User user);
// Deletes User 
bool deleteUserFromDB(const User user);



#endif
