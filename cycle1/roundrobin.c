#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid[10], burst_time[10], wait_time[10], turnaround_time[10], arrival_time[10], remaining_time[10], i, j, n, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d arrival time: ", i+1);
        scanf("%d", &arrival_time[i]);
        printf("Process %d burst time: ", i+1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    int time = 0, total_burst_time = 0, completed_processes = 0;
    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= time) {
                pid[i] = fork();

                if (pid[i] == 0) {
                    // Child process
                    if (remaining_time[i] <= time_quantum) {
                        sleep(remaining_time[i]);
                        printf("Process %d with burst time %d has completed.\n", i+1, remaining_time[i]);
                        exit(remaining_time[i]);
                    }
                    else {
                        sleep(time_quantum);
                        remaining_time[i] -= time_quantum;
                        printf("Process %d with burst time %d has been preempted.\n", i+1, remaining_time[i]);
                        exit(0);
                    }
                }
                else {
                    // Parent process
                    waitpid(pid[i], &wait_time[i], 0);
                    wait_time[i] /= 1000000; // Converting microseconds to milliseconds
                    if (WIFEXITED(wait_time[i])) {
                        // Child process completed normally
                        remaining_time[i] = 0;
                        wait_time[i] = time - arrival_time[i] - wait_time[i];
                        turnaround_time[i] = burst_time[i] + wait_time[i];
                        printf("Process %d with burst time %d has completed.\n", i+1, burst_time[i]);
                    }
                    else {
                        // Child process was preempted
                        wait_time[i] = time - arrival_time[i];
                    }
                }
            }
        }

        time++;

        // Checking if all processes have completed
        total_burst_time = 0;
        for (i = 0; i < n; i++) {
            total_burst_time += remaining_time[i];
        }
        if (total_burst_time == 0) {
            completed_processes = n;
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turnaround_time[i]);
    }

    return 0;
}
