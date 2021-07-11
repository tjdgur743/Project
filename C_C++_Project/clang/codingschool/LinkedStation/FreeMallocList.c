#include "StationHead.h"

void FreeMallocList(Ktx *p)
{
    Ktx *tmp = p;
    while (p != NULL)
    {
        tmp = p->Next;
        free(p);
        p = tmp;
    }
    printf("Good bye!\n");
}