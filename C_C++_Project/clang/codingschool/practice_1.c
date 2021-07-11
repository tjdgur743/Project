#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    
    int a = 50;
    int* p = &a;
    int** pp = &p;

    printf("a = %d &a = %d \n",a,&a);
    printf("p = %d &p = %d \n",p,&p);
    printf("pp = %d &pp = %d \n",pp,&pp);
    
    printf("a = %d,*p = %d,**p = %d\n",a,*p,**pp);

    return 0;
}
