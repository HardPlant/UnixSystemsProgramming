#include <string.h>
//char *strtok_r(char* s, const char* delim, char** save_ptr)
#define LINE_DELIMITERS "\n"
#define WORD_DELIMITERS " "

static int wordcount(char *s){
    int count = 1;
    char* save_ptr;

    if(strtok_r(s, WORD_DELIMITERS, save_ptr) == NULL)
        return 0;
    while(strtok_r(NULL, WORD_DELIMITERS, save_ptr))
        count++;
    return count;
}

double wordaverage(char *s){
    int linecount = 1;
    char *nextline;
    int words;

    nextline = strtok_r(s, LINE_DELIMITERS);
    if(nextline == NULL)
        return 0.0;
    words = wordcount(nextline);
    while((nextline = strtok_r(NULL, LINE_DELIMITERS)) != NULL){
        words += wordcount(nextline);
        linecount++;
    }
    return (double)words/linecount;
}