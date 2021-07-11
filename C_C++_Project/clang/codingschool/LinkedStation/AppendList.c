#include "StationHead.h"

Ktx *AppendList(Ktx *p)
{

    //puts("   도시를 입력하세요 : ");
    printf("도시를 입력 하세요 : ");
    while (getchar() != '\n')
        ;
    fgets(p->Station, sizeof(p->Station), stdin);
    p->Station[strlen(p->Station) - 1] = '\0';
    //gets(p->Station);

    //puts("   요금을 입력하세요 : ");
    printf("요금을 입력 하세요 : ");
    scanf("%d", &p->fee);
    p->Next = (Ktx *)malloc(sizeof(Ktx));
    p = p->Next;
    p->Next = NULL;

    return p;
}