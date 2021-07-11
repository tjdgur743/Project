#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; 
    int* p;
    printf("Input your number \n");
    scanf("%d",&n);
    p=(int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d",p+i);
        
    }
    for (int j = 0; j < n; j++) {
        
        printf("[%d] Input number : %d \n",j,*(p+j));
    }    
    
    return 0;
}
