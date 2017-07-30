#include <unistd.h>
int myarray[50000] = {1,2,3,4};

int main(){
    myarray[0] = 3;
    return 0;
}