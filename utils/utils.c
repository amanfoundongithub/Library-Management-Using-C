#include "utils.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

int strlen(char *str)
{
    int len = 0;
    char *iter = str;
    while (*iter)
    {
        len++;
        iter++;
    }
    return len;
}

void strcpy(char *src, char *tgt)
{
    int len = strlen(src);
    int i = 0;
    for (; i < len; i++)
    {
        tgt[i] = src[i];
    }
    tgt[i] = '\0';
}

char *dupstr(char *src)
{
    int srcLength = strlen(src) + 1;
    char *copy = malloc(sizeof(char) * srcLength);
    strcpy(src, copy);
    return copy;
}

bool strcmp(char *src, char *tgt)
{

    if (strlen(src) != strlen(tgt))
    {
        return false;
    }
    int len = strlen(src);
    for (int i = 0; i < len; i++)
    {
        if (src[i] != tgt[i])
        {
            return false;
        }
    }
    return true;
}

char *strcat(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int len = len1 + len2 + 1;

    char *final = (char *)malloc(sizeof(char) * len);

    int i = 0;
    for (; i < len; i++)
    {
        if (i < len1)
        {
            final[i] = str1[i];
        }
        else
        {
            final[i] = str2[i - len1];
        }
    }
    final[i] = '\0';
    return final;
}

char *numTostr(int num)
{

    char *numStr = (char *)malloc(sizeof(char) * 30);
    int digits[30];
    int count = 0;

    if (num == 0)
    {
        digits[0] = 0;
        count = 1;
    }
    else
    {
        while (num > 0)
        {
            digits[count] = num % 10;
            count++;
            num = num / 10;
        }
    }
    int i = 0;
    for (; i < count; i++)
    {
        numStr[i] = digits[count - 1 - i] + '0';
    }
    numStr[i] = '\0';
    char *trimmed = dupstr(numStr);
    free(numStr);
    return trimmed;
}

bool removeDirectory(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        perror("Unable to open directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {

        // Skip the `.` and `..` entries
        if (strcmp(entry->d_name, ".") || strcmp(entry->d_name, ".."))
        {
            continue;
        }

        char *immfile = strcat(path, "/");
        char *filepath = strcat(immfile, entry->d_name);

        struct stat statbuf;
        if (stat(filepath, &statbuf) == -1)
        {
            perror("Unable to get file status");
            closedir(dir);
            free(immfile);
            free(filepath);
            return false;
        }

        // Check if the entry is a directory or a file
        if (S_ISDIR(statbuf.st_mode))
        {
            // Recursively call removeDirectory for subdirectories
            if (removeDirectory(filepath) == -1)
            {
                closedir(dir);
                free(immfile);
                free(filepath);
                return false;
            }
        }
        else
        {
            // Remove file
            if (remove(filepath) == -1)
            {
                perror("Unable to remove file");
                closedir(dir);
                free(immfile);
                free(filepath);
                return false;
            }
        }
    }

    closedir(dir);

    // Remove the now-empty directory
    if (rmdir(path) == -1)
    {
        perror("Unable to remove directory");
        return false;
    }

    return true;
}
