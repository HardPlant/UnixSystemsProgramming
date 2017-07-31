#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int makeargv(const char *s, const char* delimiters, char*** argvp);
extern char **environ;

int main(){
    char** myargv;
    int i;
    int argc = makeargv(getenv("PATH"),":",&myargv);
    for(i=0;i<argc;i++){
        printf("%d:%s\n", i, myargv[i]);
    }
    return 0;
}