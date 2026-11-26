
#include <stdio.h>

int main()
{
    int nb, np, i, j, best;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb], allocated[nb];

    printf("Enter size of memory blocks:\n");
    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
        allocated[i] = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];

    printf("Enter size of processes:\n");
    for(i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    // Best Fit Memory Allocation
    for(i = 0; i < np; i++)
    {
        best = -1;

        for(j = 0; j < nb; j++)
        {
            if(allocated[j] == 0 &&
               block[j] >= process[i])
            {
                if(best == -1 ||
                   block[j] < block[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            allocated[best] = 1;
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++)
    {
        printf("%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

