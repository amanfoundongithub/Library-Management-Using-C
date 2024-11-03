#ifndef USER_UTILS_H_

#define USER_UTILS_H_
#include <stdbool.h>

int strlen(char* str);

void strcpy(char* src, char* tgt);

bool strcmp(char* src, char* tgt);

char* strcat(char* src, char* tgt);

char* dupstr(char* src);

char * numTostr(int num);

bool removeDirectory(const char *path);

#endif 