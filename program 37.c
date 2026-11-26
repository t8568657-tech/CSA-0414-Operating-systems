
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, total = 0;
    int request[50];

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling\n");
    printf("Seek Sequence:\n");

    printf("%d", head);

    for(i = 0; i < n; i++)
    {
        total += abs(request[i] - head);
        head = request[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    printf("\nAverage Head Movement = %.2f\n",
           (float)total / n);

    return 0;
}

