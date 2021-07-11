#include "StationHead.h"

void SearchList(Ktx *p)
{
    char FindStation[20];
    int trigger = 0;
    printf("찾을 역을 입력하세요 : ");
    scanf("%s", FindStation);
    while (p->Next != NULL)
    {

        if (strcmp(p->Station, FindStation) == 0)
        {
            puts(" ====행선지=====요금====");
            printf("|%7s  %9d    |\n", p->Station, p->fee);
            puts(" =======================");
            trigger = 1;
        }
        p = p->Next;
    }
    if (trigger == 0)
    {
        puts("역을 찾을 수 없음");
    }
}