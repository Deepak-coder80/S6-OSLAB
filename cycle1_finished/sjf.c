#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int get_smallest_incomplete(int burst_time[], int is_completed[], int n)
{
    int smallest_index = -1;
    int smallest_burst_time = __INT_MAX__;
    for (int i = 0; i < n; i++)
    {
        if (is_completed[i] == 0 && burst_time[i] < smallest_burst_time)
        {
            smallest_burst_time = burst_time[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}
int main()
{
    int pid[10], burst_time[10], wait_time[10], turnaround_time[10];
    int arrival_time[10], total_burst_time;
    int process_id[10], is_completed[10], completion_time[10];
    int i, j, n;
    int previous = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);
        total_burst_time += burst_time[i];
        process_id[i] = i + 1;
        is_completed[i] = 0;
    }

    // sort the process based on burst  time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (burst_time[i] > burst_time[j])
            {
               
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }

   
    int tWC = 0;
    for (j = 0; j < n; j++)
    {

        tWC = get_smallest_incomplete(burst_time, is_completed, n);
        is_completed[tWC] = 1;

        pid[tWC] = fork();

        if (pid[tWC] == 0)
        { // child process
            sleep(1);
            printf("Process %d started",process_id[tWC]);
            for (int k = 0; k < burst_time[i]; k++)
            {
                volatile unsigned long k;
                for (int h = 0; h < 1000000UL; h++)
                {
                    // delay
                }
            }
            printf("\nprocess %d finished\n", process_id[tWC]);
            exit(0);
        }else{
		 waitpid(pid[i], NULL, 0);
		
	}

        

        if (tWC == 0)
        {

            completion_time[tWC] = burst_time[tWC] ;
            turnaround_time[tWC] = completion_time[tWC];
            wait_time[tWC] = turnaround_time[tWC] - burst_time[tWC];
	    
        }
        else
        {

            completion_time[tWC] = completion_time[tWC-1] + burst_time[tWC];
            turnaround_time[tWC] = completion_time[tWC];
            wait_time[tWC] = turnaround_time[tWC] - burst_time[tWC];
	    
        }
	previous = tWC;
	
    }

	
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (process_id[i] > process_id[j])
            {
                
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
                temp = turnaround_time[i];
                turnaround_time[i] = turnaround_time[j];
                turnaround_time[j] = temp;
                temp = wait_time[i];
                wait_time[i] = wait_time[j];
                wait_time[j] = temp;
                temp = completion_time[i];
                completion_time[i] = completion_time[j];
                completion_time[j] = temp;
            }
        }
    }

    float averageWT = 0;
    float averageTAT = 0;
    printf("\nProcess BurstTime TurnAroudTime WaitingTime completion time\n");

    for (int i = 0; i < n; i++)
    {
        averageTAT += turnaround_time[i];
        averageWT += wait_time[i];
        printf("%d\t\t%d\t%d\t\t%d\t%d\n", process_id[i], burst_time[i], turnaround_time[i], wait_time[i], completion_time[i]);
    }

    printf("average waiting time = %.2f\n", averageWT/n);
    printf("average turnaround time = %.2f\n", averageTAT/n);
    return 0;
}
