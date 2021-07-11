#include "MountainHead.h"


int main(void)
{

    Mt m[5] = {{"불악산", 1708}, {"지리산", 1915}, {"한라산", 1950}, {"덕유산", 1614}, {"태백산", 1560}};

    int n = sizeof(m) / sizeof(Mt);

    DisplayMt(m, n, "\n * 원본 출력  *");
    SortByMount(m, n);
    SortByAlt(m, n);

    return 0;
}


