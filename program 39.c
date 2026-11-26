
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, head, size, total = 0;
    int request[50], temp;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk size: ");
    scanf("%d", &size);

    // Sort requests in ascending order
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(request[j] > request[j + 1])
            {
                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    printf("\nC-SCAN Disk Scheduling\n");
    printf("Seek Sequence:\n");
    printf("%d", head);

    // Move towards higher numbered cylinders
    for(i = 0; i < n; i++)
    {
        if(request[i] >= head)
        {
            total += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    // Move to the end of the disk
    total += abs((size - 1) - head);
    head = size - 1;
    printf(" -> %d", head);

    // Circular jump to the beginning
    total += (size - 1);
    head = 0;
    printf(" -> %d", head);

    // Service remaining requests
    for(i = 0; i < n; i++)
    {
        if(request[i] < head + size &&
           request[i] < 0)
            continue;

        if(request[i] < head + size &&
           request[i] < request[0])
            continue;
    }

    for(i = 0; i < n; i++)
    {
        if(request[i] < head)
        {
            total += abs(request[i] - head);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}

