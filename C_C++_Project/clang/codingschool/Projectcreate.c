#include <stdio.h>
#include <string.h>
#include "MountainHead.h"


int main(void)
{

    Mt m[5] = {{"설악산", 1708}, {"지리산", 1915}, {"한라산", 1950}, {"덕유산", 1614}, {"태백산", 1560}};

    int n = sizeof(m) / sizeof(Mt);

    DisplayMt(m, n, "\n * 원본 출력  *");
    SortByMount(m, n);
    SortByAlt(m, n);

    return 0;
}

void DisplayMt(Mt *m, int number, char *message)
{

    puts(message);

    for (int i = 0; i < number; i++)
    {

        printf("[%d] %s\n", i + 1, m[i].mount);
    }
}

void SortByMount(Mt *m, int number)
{
    Mt tmp;

    for (int i = 0; i < number - 1; i++)
    {

        for (int j = 0; j < number - i - 1; j++)
        {
            if (strcmp((m + j)->mount, (m + j + 1)->mount) > 0)
            {
                tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }

    printf("----------------------------------\n");
    DisplayMt(m, number, "\n * 정렬 출력  *");
}

void SortByAlt(Mt *m, int number)
{

    Mt tmp;

    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - 1 - i; j++)
        {

            if ((m + j)->alt < (m + j + 1)->alt)
            {
                tmp = *(m + j);
                *(m + j) = *(m + j + 1);
                *(m + j + 1) = tmp;
            }
        }
    }

    DisplayMt(m, number, "\n 높이로 정렬 ");
}