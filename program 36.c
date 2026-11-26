
#include <stdio.h>

int main()
{
    int n, i, blocks[50], next[50];
    int record, first, last;

    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    printf("Enter the block numbers:\n");

    for(i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    first = blocks[0];
    last = blocks[n - 1];

    for(i = 0; i < n - 1; i++)
    {
        next[i] = blocks[i + 1];
    }

    next[n - 1] = -1;

    printf("\nLinked File Allocation\n");

    printf("First Block = %d\n", first);
    printf("Last Block = %d\n", last);

    printf("\nBlock Number\tNext Block\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t", blocks[i]);

        if(next[i] == -1)
            printf("NULL\n");
        else
            printf("%d\n", next[i]);
    }

    printf("\nEnter the record position to access: ");
    scanf("%d", &record);

    if(record >= 1 && record <= n)
    {
        printf("\nAccessing record %d:\n", record);

        for(i = 0; i < record; i++)
        {
            printf("%d ", blocks[i]);
        }

        printf("\nRecord %d is stored in block %d\n",
               record, blocks[record - 1]);
    }
    else
    {
        printf("\nInvalid record position!\n");
    }

    return 0;
}

