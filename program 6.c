
#include <stdio.h>

int main()
{
    int n, i, tq, time = 0;
    int bt[20], rem_bt[20];
    int wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of processes:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    if(n <= 0 || n > 20 || tq <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Round Robin Scheduling
    while(1)
    {
        int done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem_bt[i] > 0)
            {
                done = 0;

                if(rem_bt[i] > tq)
                {
                    time += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                    tat[i] = time;
                }
            }
        }

        if(done == 1)
            break;
    }

    // Calculate average waiting and turnaround time
    for(i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

