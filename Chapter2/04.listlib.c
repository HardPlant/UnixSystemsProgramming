#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "04.listlib.h"
#define TRAV_INIT_SIZE 8

typedef struct list_struct{
    data_t item;
    struct list_struct *next;
}list_t;

static list_t endlist;
static list_t *headptr = NULL;
static list_t *tailptr = NULL;
static list_t **travptrs = NULL;
static list_t travptrs_size = 0;

int accessdata(void){
    int i;
    list_t **newptrs;
    if (headptr==NULL){
        errno = EINVAL;
        return -1;
    }
    if(travptrs_size == 0){
        travptrs = (list_t**)calloc(TRAV_INIT_SIZE, sizeof(list_t*));
        if(travptrs == NULL) return -1;
        travptrs[0] = headptr;
        travptrs_size = TRAV_INIT_SIZE;
        return 0;
    }
    for(i=0; i<travptrs_size;i++){
        if(travptrs[i] == NULL){
            travptrs[i] = headptr;
            return i;
        }
    }
    newptrs = realloc(travptrs, 2*travptrs_size*sizeof(list_t*));
    if(newptrs == NULL) return -1;
    travptrs = newptrs;
    travptrs[travptrs_size] = headptr;
    travptrs_size *= 2;
    return travptrs_size/2;
}
