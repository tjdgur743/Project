#include <stdio.h>

typedef struct Student
{
    int rank,tot;

}Student;


int main()
{
    Student sa[5]; 
    int n = sizeof(sa)/sizeof(Student);
    
    for (int i = 0; i < 5; i++)
    {

        sa[i].rank = 1;
        for (int j = 0; j < n; j++)
        {

            if ((sa[i].tot) < ((sa+j)->tot))
               sa[i].rank++;
        }
    }

    return 0;
}
