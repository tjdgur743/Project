#include <stdio.h>
#include <string.h>

typedef struct Man {

    char name[20];
    int age;
    double height;
}Man;


void DisplayMan(Man* m_,int num_,char* msg_);
void SortByName(Man* m_,int num_);
//void SortByAge(Man* m_,int num_);


int main(void)
{
   
    Man m[5] = {
    {"이순신",58,175.4},
    {"장보고",56,180.6},
    {"한석봉",34,162.9},
    {"강감찬",25,171.3},
    {"안창호",48,184.8},
    };

    int n = sizeof(m)/sizeof(Man);

    DisplayMan(m,n,"정렬 전");

    SortByName(m,n);
    
    return 0;
}
void DisplayMan(Man* m_,int num_,char* msg_){

    puts(msg_);
    for (int i = 0; i < num_; i++) {
        printf("[%d] %8s %2d %6.1f \n",i+1,(m_+i)->name,(m_+i)->age,(m_+i)->height);
    }

}

void SortByName(Man* m_,int num_){

   Man tmp; 
    for(int i = 0; i < num_-1; i++){
        for (int j = 0; j < num_-1-i; j++) {
            
            if(strcmp((m_+j)->name,(m_+j+1)->name)>0){
                tmp = *(m_+j);
                *(m_+j) = *(m_+j+1);
                *(m_+j+1) = tmp;
            }
        }

    }

    DisplayMan(m_,num_,"정렬 후");
}
