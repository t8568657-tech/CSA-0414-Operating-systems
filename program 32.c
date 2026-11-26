
#include <stdio.h>

int main()
{
    int n, frames, pages[50], frame[10];
    int i, j, k, pageFaults = 0;
    int time[10], count = 0;
    int found, lru;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                time[j] = ++count;
                break;
            }
        }

        if(found == 0)
        {
            lru = 0;

            for(j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    lru = j;
                    break;
                }

                if(time[j] < time[lru])
                    lru = j;
            }

            frame[lru] = pages[i];
            time[lru] = ++count;
            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(k = 0; k < frames; k++)
        {
            if(frame[k] == -1)
                printf("- ");
            else
                printf("%d ", frame[k]);
        }

        if(found == 0)
            printf("\tPage Fault");
        else
            printf("\tHit");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Page Hits = %d\n", n - pageFaults);

    return 0;
}

