#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int k;
    do
    {
        k = get_int("Type a number: ");
    }
     while (k < 2);

    for (int i = 2; i <= k; i++)
    {
        int foss = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                foss = 0;
                break;
            }
        }
        if (foss) {
            printf("%d\n", i);
        }
    }

    return 0;
}

