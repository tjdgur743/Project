#include <stdio.h>
#define MUL(x,y) (x) * (y)
#define P printf    

int main () {

    P("MUL(10) = %d \n",MUL(10,20));
    P("MUL(3+5) = %d \n",MUL(3,3+5));
    P("%d \n", 100+MUL(2,2+3));


   return 0;
}