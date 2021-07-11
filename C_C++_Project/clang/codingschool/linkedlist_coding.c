#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Ktx
{

    char ktxStation[20];
    int ktxFee;
    struct Ktx *Next;
} Ktx;

char MenuKtx();
Ktx *AppendList(Ktx *p);
Ktx *InsertList(Ktx *p);
void UpdateList(Ktx *p);
Ktx *DeleteList(Ktx *p);
void SearchList(Ktx *p);
int DisplayList(Ktx *p);
void FreeMallocList(Ktx *p);

int main(void)
{

    Ktx *tail, *head = (Ktx *)malloc(sizeof(Ktx));
    head->Next = NULL;
    tail = head;
    while (1)
    {
        switch (MenuKtx())
        {

        case '1' /* variable case */:
            tail = AppendList(tail);
            break;
        case '2':
            head = InsertList(head);
            break;
        case '3':
            UpdateList(head);
            break;
        case '4':
            head = DeleteList(head);
            break;
        case '5':
            SearchList(head);
            break;
        case '6':
            DisplayList(head);
            getchar();
            break;
        case '0':
            FreeMallocList(head);
            exit(0);
        default:
            puts(" 없는 메뉴.. \a\a");
        }
    }
    getchar();
    return 0;
}

char MenuKtx()
{
    char number;
    system("cls");
    puts("*** 링크드 리스트 *** ");
    puts(" 1. AppendList (추가)");
    puts(" 2. InsertList (입력)");
    puts(" 3. UpdateList (수정)");
    puts(" 4. DeleteList (삭제)");
    puts(" 5. SearchList (찾기)");
    puts(" 6. DisplayList (출력)");
    puts(" 0. QuitList (종료)");
    puts(" **********************");
    printf(" 번호 선택 [     ]\b\b\b");
    number = getchar();
    return number;
}

Ktx *AppendList(Ktx *p)
{
    printf("KTX역 이름을 입력 : \n");
    while (getchar() != '\n')
        ;
    fgets(p->ktxStation, sizeof(p->ktxStation), stdin);
    p->ktxStation[strlen(p->ktxStation) - 1] = '\0';

    printf("서울에서부터 요금은 : ");
    scanf("%d", &p->ktxFee);
    p->Next = (Ktx *)malloc(sizeof(Ktx));
    p = p->Next;
    p->Next = NULL;
    return p;
}

Ktx *InsertList(Ktx *p)
{

    int pos, number;
    Ktx *item;
    Ktx *start = p;
    item = (Ktx *)malloc(sizeof(Ktx));
    number = DisplayList(p);
    do
    {
        printf("==> 삽입할 위치는 : \n");
        scanf("%d", &pos);
    } while (pos < 1 || pos > number);
    printf(" KTX 역 이름 입력 : \n");
    while (getchar() != '\n')
        ;
    //gets(item->ktxStation);
    fgets(item->ktxStation, sizeof(item->ktxStation), stdin);
    item->ktxStation[strlen(item->ktxStation) - 1] = '\0';

    printf("서울에서부터 요금은 : \n");
    scanf("%d", &item->ktxFee);
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
int DisplayList(Ktx *p)
{
    int i = 1;
    puts("\t---------------------");
    puts("\t 번호 역 이름 요금 ");
    puts("\t---------------------");
    while (p->Next != NULL)
    {
        printf("\t %3d %8s %6d 원\n", i++, p->ktxStation, p->ktxFee);
        p = p->Next;
    }
    puts("\t---------------------");
    puts("\t아무키나 누르세요!!!");
    getchar();
    return i - 1;
}
void UpdateList(Ktx *p)
{
    int pos, number;
    Ktx tmp;
    number = DisplayList(p);
    do
    {
        printf("=>수정할 번호는:");
        scanf("%d", &pos);
    } while (pos < 1 || pos > number);
    if (pos == 1)
    {
        printf("변경할 역 이름:");
        fflush(stdin);
        gets(p->ktxStation);
        printf("변경된 요금은:");
        scanf("%d", &p->ktxFee);
        printf("%s역 %d원==>%s역 %d원으로 변경\n", tmp.ktxStation, tmp.ktxFee, p->ktxStation, p->ktxFee);
        getchar();
    }
    else
    {
        int i;
        for (i = 1; i < pos; i++)
        {
            p = p->Next;
        }
        tmp = *p;
        printf("변경할 역 이름:");
        fflush(stdin);
        gets(p->ktxStation);
        printf("변경된 요금은:");
        scanf("%d", &p->ktxFee);
        printf("%s역 %d원==>%s역 %d원으로 변경\n", tmp.ktxStation, tmp.ktxFee, p->ktxStation, p->ktxFee);
        getchar();
    }
    getchar();
}
Ktx *DeleteList(Ktx *p)
{
    int pos, number;
    Ktx *start = p;
    number = DisplayList(p);
    do
    {
        printf("=>삭제할 번호는:");
        scanf("%d", &pos);
    } while (pos < 1 || pos > number);
    if (pos == 1)
    {
        start = p->Next;
        free(p);
    }
    else
    {
        int i;
        Ktx *tmp;
        for (i = 1; i < pos - 1; i++)
        {
            p = p->Next;
        }
        tmp = p->Next;
        p->Next = p->Next->Next;
        free(tmp);
    }
    return start;
}
void SearchList(Ktx *p)
{
    char findStation[20];
    int sw = 0;
    printf("찾을 역 이름:");
    fflush(stdin);
    gets(findStation);
    while (p->Next != NULL)
    {
        if (strcmp(findStation, p->ktxStation) == 0)
        {
            printf("찾음.%s역은 %d원\n", p->ktxStation, p->ktxFee);
            sw = 1;
        }
        p = p->Next;
    }
    if (!sw)
    {
        printf("%s역은 존재하지 않음\a\a\n", findStation);
    }
    getchar();
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
    puts("Good-bye!!!");
}
