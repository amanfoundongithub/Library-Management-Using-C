#include <stdio.h>
#include "user/user.h"
#include "book/book.h"


int main(void){

    User user1 = createUser("harsh@mail.com", "1234", "harsh_1234");

    User user2 = createUser("harsh2@mil.com", "1", "iu383");

    Book book1 = createNewBook(12, "How I met myself", 120, 19);

    issueBook(user1,"1234", book1);

    issueBook(user1,"", book1);

    issueBook(user2,"1", book1);

    printUser(user1);

    return 0;
}