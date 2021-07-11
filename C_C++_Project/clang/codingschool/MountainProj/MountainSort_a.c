#include "MountainHead.h"

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

    DisplayMt(m, number, "\n 높은 산으로 정렬 ");
}