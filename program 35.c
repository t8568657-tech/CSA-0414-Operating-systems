
#include <stdio.h>

int main()
{
    int n, i, indexBlock, record, blocks[50];

    printf("Enter the index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter the number of records: ");
    scanf("%d", &n);

    printf("Enter the block numbers of the file:\n");

    for(i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nIndexed File Allocation\n");
    printf("Index Block = %d\n", indexBlock);

    printf("\nIndex\tBlock Number\n");

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
    }
    else
    {
        printf("\nInvalid record number!\n");
    }

    return 0;
}

