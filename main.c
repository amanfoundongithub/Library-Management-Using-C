#include <stdio.h>
#include "user/user.h"
#include "book/book.h"


int main(void){

    User arr[10];

    char* names[10] = {
        "harsh",
        "yuvraj",
        "dhoni",
        "kohli",
        "raina",
        "jadeja",
        "surya",
        "rachin",
        "rohit",
        "helmet"
    };

    for(int i = 0 ; i < 10 ; i++) {
        arr[i] = createUser(names[i], names[i], names[i]);
    }

    
    Book books[5];

    books[0] = createNewBook(109, "Atlas Shrugged", "Ayn Rand", 520, 10);
    books[1] = createNewBook(110, "NCERT", "NCERT", 1025, 12);
    books[2] = createNewBook(111, "j","frfr",20, 22);
    books[3] = createNewBook(113, "eief","frfr",20, 22);
    books[4] = createNewBook(119, "wdehfefe","frfr",20, 22);

    issueBook(arr[3], names[3], books[3]);
    issueBook(arr[3], names[3], books[1]);
    issueBook(arr[5], names[4], books[0]);
    issueBook(arr[5], names[5], books[0]);

    returnBook(arr[6], names[6], books[3]);
    returnBook(arr[3], names[3], books[3]);

    issueBook(arr[6], names[6], books[3]);

    for(int i = 0 ; i < 10 ; i++) {
        saveUserToDB(arr[i]);
    }

    User finduser = retrieveUserfromDB("jadeja");

    printUser(finduser);

    for(int i = 0 ; i < 5 ; i++){
        printBook(books[i]);
    }

    return 0;
}