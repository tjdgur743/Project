#include "StationHead.h"

Ktx *DeleteList(Ktx *p)
{
    Ktx *tmp;
    Ktx *Start = p;
    int m, n;
    m = DisplayList(p);
    printf("삭제할 번호를 입력하세요 [   ]\b\b\b");
    n = scanf("%d", &n);
    while (n < 1 || n > m)
        ;
    if (n == 1)
    {
        Start = p->Next;
        free(p);
        return Start;
    }
    else
    {
        for (int j = 1; j < n - 1; j++)
        {
            p = p->Next;
        }
        tmp = p->Next;
        p->Next = p->Next->Next;
        free(tmp);
    }
    return Start;
}