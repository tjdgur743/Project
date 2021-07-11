#include <stdio.h>
#include <string.h>

typedef struct ST { //13byte

    char a;
    int b;
    double d;
}ST;

typedef union UN //8byte
{
    char a;
    int b;
    double d;

}UN;

int main(void)
{
    printf("AA = %d byte \n", sizeof(ST));
    printf("BB = %d byte \n\n",sizeof(UN));
    
    ST k = {'$',30,3.14};
    printf(" k ==> %c, %d, %.2f \n", k.a,k.b,k.d);

    UN t;
    t.a='#';
    printf("t ==> %d\n",t.a);

    t.b = 50;
    printf("t ==> %.2f\n",t.b);

    t.d =4.555;
    printf("t ==> %.2f\n",t.d);
    
    return 0;
}
