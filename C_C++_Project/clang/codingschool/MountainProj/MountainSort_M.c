#include "MountainHead.h"

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