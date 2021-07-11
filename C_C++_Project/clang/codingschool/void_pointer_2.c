#include <stdio.h>

int main(void)
{
    int a = 100;
    char b ='k';
    double d = 55.77;


    void* p = &a;
    p = &b;
    p = &d;

    return 0;
}
