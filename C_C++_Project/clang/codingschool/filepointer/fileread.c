#include <stdio.h>

int main()
{

    //char str[50] = {0};
    char c = 0;
    FILE *fp = fopen("//home//kim//clang//codingschool//filepointer//a.txt", "r");

    if (fp == NULL)
        fputs("파일 열기 실패!!", stdout);
    while (c != EOF)
    {

        c = fgetc(fp);
        putchar(c);
    }
    puts(" ");

    //fgets(str, sizeof(str), fp);
    //printf("\n",fputs(str, stdout));

    fclose(fp);

    return 0;
}