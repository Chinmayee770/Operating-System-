#include <stdio.h>

int main() {
    int bt[20], pid[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the Burst Time:");
    for (i = 0; i < n; i++) {
        printf("\np%d:", i + 1);
        scanf("%d", &bt[i]);
        pid[i] = i + 1;
    }

    // Sorting of burst times
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
    }

    printf("\n");
    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("Process ID     Burst Time     Waiting Time     Turnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
        printf("\n");
    }

    avg_tat = (float)total / n;
    printf("Average Waiting Time=%f\n", avg_wt);
    printf("Average Turnaround Time=%f\n", avg_tat);

    return 0;
}
