#include <stdio.h>

int main(void)
{

char b_type;
char it[20];
int age;
    fputs("삶은 속도가 아니라 방향이다 \n", stdout);//fputs 은 자동 줄바꿈이 없음 

    fprintf(stdout,"%d, %.1f %c %s \n",20,3.14,'a',"korea");//가장 먼저 stream

   // b_type = fgetc(stdin);

   // fprintf(stdout,"%c형 이군요. 반갑습니다. \n",b_type);

//    fgets(it,sizeof(it),stdin);

    
 //   fprintf(stdout,"%s. 저도 그 회사 가고 싶어요  \n",it);


fscanf(stdin,"%d",&age);
fprintf(stdout," %d살. 입니다 .",age);
  


    return 0;
}