#include "dbms.h"
#include "dbms_def.c"
#include "../utils/utils.h"

#include <stdlib.h>

#include <stdio.h>

Db initDb(const char* rootDir, const char* type) {

    Db database = (Db) malloc(sizeof(struct db));

    database->rootDir = dupstr(rootDir);
    database->type = dupstr(type);

    return database;
}

bool deleteDb(Db db) {

    removeDirectory(db->rootDir);

    free(db->rootDir);
    free(db->type);

    free(db);
    
}

