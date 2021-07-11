#include "StationHead.h"

int DisplayList(Ktx *p)
{
    int i = 1;

    puts("=======================");
    puts("====행선지=====요금====");
    while (p->Next != NULL)
    {
        printf("[%d]%7s %9d\n", i++, p->Station, p->fee);
        p = p->Next;
    }
    puts("=======================");
    puts("====아무키나 누르세요====");

    getchar();

    return i - 1;
}