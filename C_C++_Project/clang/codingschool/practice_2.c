#include <stdio.h>
#include <stdlib.h>

typedef struct Ktx
{
    char ktxStation[20];
    int fee;
    struct Ktx *Next;
} Ktx;

int Menu();
Ktx *AppendList(Ktx *p);
int DisplayList(Ktx *p);
Ktx *InsertList(Ktx *p);
void FreeMallocList(Ktx *p);

int main()
{

    Ktx *tail, *head = (Ktx *)malloc(sizeof(Ktx));
    head->Next = NULL;
    tail = head;
    while (1)
    {

        switch (Menu())
        {
        case '1':
            tail = AppendList(tail);
            break;
        case '2':
            DisplayList(head);
            getchar();
            break;
        case '3':
            head = InsertList(head);
            break;

        case '0':
            FreeMallocList(head);
            exit(0);

        default:
            break;
        }
    }
    getchar();
    return 0;
}
int Menu()
{

    int i;
    printf("-----------------\n");
    printf("1. 추가\n");
    printf("2. 출력\n");
    printf("3. 수정\n");
    printf("4. 정렬\n");
    printf("0. 나가기\n");

    printf("-----------------\n");
    printf("선택하세요 [  ]\b\b\b");
    i = getchar();

    return i;
}

Ktx *AppendList(Ktx *p)
{
    printf("도시를 입력하세요 :  \n");
    gets(p->ktxStation);
    while (getchar() != '\n')
        ;
    printf("요금을 입력하세요 : \n");
    scanf("%d", &p->fee);
    p->Next = (Ktx *)malloc(sizeof(Ktx));
    p = p->Next;
    p->Next = NULL;
    return p;
}
int DisplayList(Ktx *p)
{
    int i = 1;
    puts("\t------ktx------");
    puts("\t 번호 역 이름 요금");
    puts("\t---------------");
    while (p->Next != NULL)
    {
        printf("\t %3d %8s %6d 원\n", i++, p->ktxStation, p->fee);
        p = p->Next;
    }
    puts("\t---------------");
    puts("\t 아무키나 누르세요");

    getchar();
    return i - 1;
}

void FreeMallocList(Ktx *p)
{
    Ktx *tmp = p;
    while (p != NULL)
    {
        tmp = p->Next;
        free(p);
        p = tmp;
    }
    puts("Good-bye!!");
}

Ktx *InsertList(Ktx *p)
{
    int pos, number;
    Ktx *start = p;
    Ktx *item = (Ktx *)malloc(sizeof(Ktx));
    number = DisplayList(p);
    do
    {
        printf(" 삽입할 위치는 ? : \b\b");
        scanf("%d", &pos);
    } while (pos < 1 || pos > number);
    printf("Ktx 역 이름 입력 : \n");
    gets(item->ktxStation);
    while (getchar() != '\n')
        ;
    printf("요금을 입력하세요");
    scanf("%d", &item->fee);
    if (pos == 1)
    {
        item->Next = p;
        start = item;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->Next;
        }

        item->Next = p->Next;
        p->Next = item;
    }
    return start;
}