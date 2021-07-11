#include <stdio.h>

int main(void)
{

    putchar('A');
    putchar('B');
    putchar('C');
    putchar('\n');


fputc('A',stdout);
fputc('B',stdout);
fputc('C',stdout);
fputc('\n',stdout);

    putchar(97);
    putchar(98);
    putchar(99);
    putchar('\n');

fputc(97,stdout);
fputc(98,stdout);
fputc(99,stdout);
fputc(10,stdout);


    return 0;
}