#include <stdio.h>
#include <string.h>

typedef struct OX1 {
    
    unsigned  char a;
    signed char b;
    unsigned char c;
    signed char d;
}OX1;

typedef struct OX2 {

    unsigned char a : 1;
    signed char b : 1;
    unsigned char c : 2;
    signed char d : 2;

}OX2;

int main(void)
{
    printf(" OX1 = %d byte \n", sizeof(OX1));
    printf(" OX2 = %d byte \n", sizeof(OX2));

    return 0;
}


