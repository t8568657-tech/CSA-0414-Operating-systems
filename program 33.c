
#include <stdio.h>

int main()
{
    int n, frames, pages[50], frame[10];
    int i, j, k, pageFaults = 0;
    int found, pos, farthest, next;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            pos = -1;
            farthest = -1;

            for(j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }

                next = n;

                for(k = i + 1; k < n; k++)
                {
                    if(pages[k] == frame[j])
                    {
                        next = k;
                        break;
                    }
                }

                if(next > farthest)
                {
                    farthest = next;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
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

