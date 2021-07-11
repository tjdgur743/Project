#include "MountainHead.h"

void DisplayMt(Mt *m, int number, char *message)
{

    puts(message);

    for (int i = 0; i < number; i++)
    {

        printf("[%d] %s\n", i + 1, m[i].mount);
    }
}