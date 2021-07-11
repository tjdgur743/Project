#include <stdio.h>
#include <string.h>
#pragma pack(1)

typedef struct Date{
    int year, month ,day;
}Date;

typedef struct Man {

    char name[20];
    Date birth;
    int age;
    double height;
}Man;

int main(void)
{
    Man m = {"이순신",{1860,2,15},58,175.4};

    printf("Man = %d byte \n",sizeof(Man));

    printf("name = %s \n",m.name);
    printf("year = %d \n",m.birth.year);
    printf("month = %d\n",m.birth.month);
    printf("day = %d\n",m.birth.day);
    printf("age = %d\n",m.age);
    printf("height = %.1f\n",m.height);

    return 0;
}
