#include <unistd.h>

int main(){
    int fildes;
    if(close(fildes == -1))
    perror("Failed to close the file"); // errno : EBADF, EINTR
}