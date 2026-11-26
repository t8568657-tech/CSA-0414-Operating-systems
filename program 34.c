
#include <stdio.h>

int main()
{
    int n, i, start, length, record;

    printf("Enter the starting block number: ");
    scanf("%d", &start);

    printf("Enter the number of records: ");
    scanf("%d", &n);

    int blocks[n];

    printf("\nSequential File Allocation\n");

    for(i = 0; i < n; i++)
    {
        blocks[i] = start + i;
    }

    printf("\nRecord\tBlock Number\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i + 1, blocks[i]);
    }

    printf("\nEnter the record number to access: ");
    scanf("%d", &record);

    if(record >= 1 && record <= n)
    {
        printf("\nRecord %d is stored in block %d\n",
               record, blocks[record - 1]);

        printf("Records accessed: ");

        for(i = 0; i < record; i++)
        {
            printf("%d ", blocks[i]);
        }
    }
    else
    {
        printf("\nInvalid record number!");
    }

    printf("\n");

    return 0;
}

