#ifndef DBMS_H_
#define DBMS_H_

#include <stdbool.h>

typedef struct db* Db;

Db initDb(const char* rootDir,const char* type);

bool deleteDb(Db db);



#endif