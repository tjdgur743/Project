#include <stdio.h>
#include<string.h>

int main()
{

    char str[50] = "대한민국은 민주 공화국이다.";

    FILE *fp = fopen("//home//kim//clang//codingschool//filepointer//b.txt", "w");

    if (fp == NULL)
        fputs("파일 열기 실패!!", stdout);

    //fputs(str,stdout);
    strcpy(str, "모든 권력은 국민으로부터 나온다.");
    fputs(str, fp);

    fclose(fp);

    return 0;
}