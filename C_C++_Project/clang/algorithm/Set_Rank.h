#include <stdio.h>

typedef struct Student
{
    char name[20];
    int rank;
    int tot;

} Student;

void Set_Rank(Student *s_, int num_)
{
    int i, j;
    for (int i = 0; i < num_; i++)
    {
        (s_ + i)->rank = 1;
        for (int j = 0; j < num_; j++)
        {
            if ((s_ + i)->tot < (s_ + j)->tot)
            {
                (s_ + i)->rank++;
            }
        }
    }
}