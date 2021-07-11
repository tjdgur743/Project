#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,i;
    int* p;

    printf(" 처리할 데이터의 개수는 : \n");
    scanf("%d",&n);
    
    p = (int*)malloc(sizeof(int)*n);
    if(p == NULL){
        puts("malloc fail");

    }
    printf("size of p : %ld\n",p);

    printf("[%d] 개의 정수 입력 \n", n);
    for (i = 0; i < n; i++) {
        
        printf("[%d] 번째 정수 :  ", i);
        scanf("%d",p+i);
        
    }

    printf("\n [%d]개 정수 원본 출력 \n", n);
    for (i = 0; i < n; i++) {

        
        printf("[%d] ==> %d \n",i,*(p+i));
    }
    free(p);
    
    return 0;
}
