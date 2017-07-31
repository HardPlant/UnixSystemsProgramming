#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define PATH_DELIMITERS ":"
int makeargv(const char *s, const char* delimiters, char*** argvp);
extern char **environ;
char** getpath(void){
    char** myargv;
    char* path;
    int i;

    path = getenv("PATH");
    if(makeargv(path,PATH_DELIMITERS,&myargv) == -1)
        return NULL;
    else
        return myargv;
}