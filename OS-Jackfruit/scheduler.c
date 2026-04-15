#include <stdio.h>

void fcfs(int n, int bt[]) {
    int wt[n], tat[n];

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\n--- FCFS Scheduling ---\n");
    printf("Process\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}

void round_robin(int n, int bt[], int tq) {
    int rem_bt[n], wt[n], tat[n];
    
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    int time = 0;

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\n--- Round Robin Scheduling ---\n");
    printf("Process\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
}

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n];

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    printf("Enter time quantum (for Round Robin): ");
    scanf("%d", &tq);

    fcfs(n, bt);
    round_robin(n, bt, tq);

    return 0;
}