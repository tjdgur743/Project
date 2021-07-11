#include "StationHead.h"

char MenuKtx()
{

    int n;
    puts("  ----------------");
    puts("  |  [1] Append  |");
    puts("  |  [2] Insert  |");
    puts("  |  [3] Update  |");
    puts("  |  [4] Delete  |");
    puts("  |  [5] Display |");
    puts("  |  [6] Search  |");
    puts("  |  [0] Close   |");
    puts("  ---------------- ");
    printf("선택하세요 : [   ]\b\b\b");
    scanf("%d", &n);

    return n;
}