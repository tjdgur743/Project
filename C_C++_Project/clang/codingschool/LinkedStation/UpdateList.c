#include "StationHead.h"

void UpdateList(Ktx *p)
{
    int m, n;
    m = DisplayList(p);
    printf("수정할 번호를 입력하세요 [  ]\b\b\b");
    n = scanf("%d", &n);

    if (n > 0 || n < m)
    {
        for (int i = 1; i < m; i++)
        {
            p = p->Next;
        }
        printf("도시를 입력 하세요 : ");
        while (getchar() != '\n')
            ;
        fgets(p->Station, sizeof(p->Station), stdin);
        p->Station[strlen(p->Station) - 1] = '\0';
        printf("요금을 입력 하세요 : ");
        scanf("%d", &p->fee);
    }
}