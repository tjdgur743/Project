#include "StationHead.h"

int main(void)
{
    Ktx *head, *tail = (Ktx *)malloc(sizeof(Ktx));
    head = tail;

    while (1)
    {
        switch (MenuKtx())
        {
        case 1:
            tail = AppendList(tail);
            break;
        case 0:
            FreeMallocList(head);
            return 0;
        case 2:
            head = InsertList(head);
            break;
        case 3:
            UpdateList(head);
            break;
        case 4:
            head = DeleteList(head);
            break;
        case 5:
            DisplayList(head);
            getchar();
            break;
        case 6:
            SearchList(head);
            break;
        default:
            break;
        }
    }
}
