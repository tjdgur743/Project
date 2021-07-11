#include <stdio.h>

int main()
{
  //---------파일 읽기-------------------
  // char s[50] = {0};
  // FILE *fp = fopen("//home//kim//clang//codingschool//filepointer//b.txt", "r");

  // if (fp == NULL)
  // {
  //     printf("파일 읽기 실패! \n");
  // }

  // fgets(s, sizeof(s), fp);
  // fputs(s,stdout);
  // puts(" ");

  // while (s != EOF)
  // {
  //     s = fgetc(fp);
  //     putchar(s);
  // }
  // puts(" ");
  //fclose(fp);
  //-------------------------------------
  char s[60] = {0};
  char c = 0;
  FILE *fp = fopen("//home//kim//clang//codingschool//filepointer//b.txt", "r+");

  for (int i = 0; i < 5; i++)
  {

    fgets(s, sizeof(s), stdin);
    fputs(s, fp);
  }
  printf("----------------------\n");
  rewind(fp);
  while (c != EOF)
  {
    c = fgetc(fp);
    putchar(c);
  }
  puts(" ");

  // fputs(s,fp);
  // puts(" ");
  // fputs(s,stdout);

  fclose(fp);

  return 0;
}