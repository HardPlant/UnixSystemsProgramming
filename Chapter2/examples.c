#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fildes;
    if(close(fildes) == -1)
    fprintf(stderr, "Failed to close file decsriptor %d: %s\n",
        fildes, strerror(errno));
}