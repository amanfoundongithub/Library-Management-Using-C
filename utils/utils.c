#include "utils.h"
#include <stdbool.h>

int strlen(char* str){
    int len = 0;
    char* iter = str; 
    while(*iter) {
        len++;
        iter++;
    }
    return len;
}

void strcpy(char* src, char* tgt) {
    int len = strlen(src);
    int i = 0;
    for( ; i < len ; i++){
        tgt[i] = src[i];
    }
    tgt[i] = '\0';
}

bool strcmp(char* src, char* tgt) {
    
    if(strlen(src) != strlen(tgt)){
        return false;
    }
    int len = strlen(src);
    for(int i = 0 ; i < len ; i++) {
        if(src[i] != tgt[i]) {
            return false;
        }
    }
    return true;
}


char* dupstr(char* src){
    int srcLength = strlen(src) + 1;
    char* copy = malloc(sizeof(char) * srcLength);
    strcpy(src, copy);
    return copy;
}
