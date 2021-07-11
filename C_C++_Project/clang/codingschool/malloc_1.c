#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 400;
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL)
    {
        puts("malloc fail");
    }
    *p = 30;

    printf(" a = %d, &a = %d \n", a, &a);
    printf(" *p = %d, p = %d, &p=%d\n", *p, p, &p);

    free(p);

    return 0;
}
