#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

static int count = 0;
// internal linkage; this var will only used in this c file(bubblesort.c)
static int onepass(int a[], int n){
    int i;
    int interchanges = 0;
    int temp;
    for (i=0; i<n-1; i++)
    if (a[i] > a[i+1]){
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        interchanges = 1;
        count++; // static int
    }
    return interchanges;
}