#include <stdio.h>

void add(int x,int y){
    printf(" %d + %d = %d \n",x,y,x+y);
}

    int main(void)
    {
        
        void(*p)(int,int) =add;
        add(10,20);
        p(30,50);
        printf("add = %d , p = %d \n",add, p);
        return 0;
    }
