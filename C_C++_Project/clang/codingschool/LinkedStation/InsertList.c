#include "StationHead.h"

Ktx *InsertList(Ktx *p)
{
    Ktx *tmp = (Ktx *)malloc(sizeof(Ktx));
    Ktx *Start = p;
    int n, m;
    m = DisplayList(p);
    printf("추가할 숫자를 선택하세요 [   ]\b\b\b");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("도시를 입력 하세요 : ");
        while (getchar() != '\n')
            ;
        fgets(tmp->Station, sizeof(tmp->Station), stdin);
        tmp->Station[strlen(tmp->Station) - 1] = '\0';
        printf("요금을 입력 하세요 : ");
        scanf("%d", &tmp->fee);
        tmp->Next = p;
        return tmp;
    }
    if (n > 1 || n < m)
    {
        for (int i = 1; i < n - 1; i++)
        {
            p = p->Next;
        }
        tmp->Next = p->Next;
        p->Next = tmp;
        printf("도시를 입력 하세요 : ");
        while (getchar() != '\n')
            ;
        fgets(tmp->Station, sizeof(tmp->Station), stdin);
        tmp->Station[strlen(tmp->Station) - 1] = '\0';
        printf("요금을 입력 하세요 : ");
        scanf("%d", &tmp->fee);
    }
    return Start;
}