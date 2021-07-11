#include <stdio.h>
#include <string.h>

typedef struct Man {

    char name[20];
    int age;
    double height;

}Man;


int main(void)
{

    Man m[5] = {
    {"이순신",58,175.4},
    {"장보고",56,180.6},
    {"한석봉",34,162.9},
    {"강감찬",25,171.3},
    {"안창호",48,184.8},
    };

    Man* p = m;
    Man tmp;

    int i, n = sizeof(m)/sizeof(Man);

    puts("원 본 ");

    for (i = 0; i < n; i++) {
       printf("[%d]%8s %2d %6.1f \n",i+1,(p+i)->name,(p+i)->age,(p+i)->height); 
        
    };
    
    
    for(i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++) {
            
            if(strcmp(m[j].name,m[j+1].name)>0){
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
            }
        }

    }
    printf("정 렬 \n");

    for (i = 0; i < n; i++) {
       printf("[%d]%8s %2d %6.1f \n",i+1, (p+i)->name,(p+i)->age,(p+i)->height); 
    };

    
    return 0;
}
