#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Ktx
{
    char Station[20];
    int fee;
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
