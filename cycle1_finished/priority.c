#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    // variables
    int pid[10], burst_time[10], priority[10];
    int wait_time[10], completion_time[10], turnaround_time[10];
    int is_completed[10], process_id[10];
    int i, n, j;
    int tWC = 0;
    float average_wait_time = 0;
    float average_turnaround_time = 0;
    // read
    printf("Enter number of process : ");
    scanf("%d", &n);

    printf("Enter process burst time and priority\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of process %d : ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter priority of process %d : ", i + 1);
        scanf("%d", &priority[i]);
        is_completed[i] = 0;
        process_id[i] = i + 1;
    }

    // sort the process based on the priority
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        tWC = i;

        // do this job
        pid[tWC] = fork();
        if (pid[tWC] == 0)
        {
            // child
            printf("process %d is running\n", process_id[tWC]);
            sleep(1);
            printf("process %d is completed\n", process_id[tWC]);
            exit(0);
        }
        else
        {
            // parent
            waitpid(pid[tWC], NULL, 0);
        }

        // calculate wait time and completion time and turnaround time
        if (i == 0)
        {
            wait_time[tWC] = 0;
            completion_time[tWC] = burst_time[tWC];
            turnaround_time[tWC] = completion_time[tWC];
        }
        else
        {
            wait_time[tWC] = completion_time[tWC - 1];
            completion_time[tWC] = wait_time[tWC] + burst_time[tWC];
            turnaround_time[tWC] = completion_time[tWC];
        }
    }

    // sort the process based on the process id
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (process_id[i] > process_id[j])
            {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
                temp = wait_time[i];
                wait_time[i] = wait_time[j];
                wait_time[j] = temp;
                temp = completion_time[i];
                completion_time[i] = completion_time[j];
                completion_time[j] = temp;
                temp = turnaround_time[i];
                turnaround_time[i] = turnaround_time[j];
                turnaround_time[j] = temp;
            }
        }
    }

    // print
    printf("process id\tburst time\tpriority\twait time\tcompletiontime\tturnaround time\n");
    for (i = 0; i < n; i++)
    {
        average_wait_time += wait_time[i];
        average_turnaround_time += turnaround_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], priority[i], wait_time[i], completion_time[i], turnaround_time[i]);
    }

    average_wait_time = average_wait_time / n;
    average_turnaround_time = average_turnaround_time / n;

    printf("Average wait time = %.2f\n", average_wait_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}