#include <stdio.h>
#include <string.h>

typedef struct Mt
{
    char mount[20];
    int alt;
} Mt;

void DisplayMt(Mt *m, int number, char *message);
void SortByMount(Mt *m, int number);
void SortByAlt(Mt *m, int number);
