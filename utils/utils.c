#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>


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

char* dupstr(char* src){
    int srcLength = strlen(src) + 1;
    char* copy = malloc(sizeof(char) * srcLength);
    strcpy(src, copy);
    return copy;
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


char* strcat(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int len = len1 + len2 + 1;

    char* final = (char *) malloc(sizeof(char) * len);

    int i = 0;
    for(; i < len ; i++) {
        if(i < len1) {
            final[i] = str1[i];
        }
        else {
            final[i] = str2[i - len1];
        }
    }

    final[i] = '\0';
    return final;
}   

