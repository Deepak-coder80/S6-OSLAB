#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
  
void main(){
	int n;
	
	// take number of process
	printf("Enter number of process : ");
	scanf("%d",&n);
	
	// array for storing arrival,burst,completion,turn around and wait time
	int at[n],bt[n],ct[n],wt[n],tat[n],pid[n];
	
	for(int i =0;i<n;i++){
		// take arrival time and burst time
		printf("Enter arrival time of  process %d:",i+1);
		scanf("%d",&at[i]);
		printf("Enter  burst time of  process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	for(int i = 0;i<n;i++){	
		pid[i] = fork();

		if(pid[i]==0){ // child process
			sleep(at[i]);
			printf("Process %d started",i+1);
			for(int j =0;j<bt[i];j++){
				volatile unsigned long k;
				for( k =0;k<1000000UL;k++){
					//delay
				}
			}
			printf("\nprocess %d finished\n",i+1);
			exit(0);
		}
	}

	// wait for child process to complete
	for(int i = 0;i<n;i++){
		waitpid(pid[i],NULL,0);
	}
	

	ct[0] = bt[0]+at[0];
	tat[0] = ct[0]-at[0];
	wt[0] = tat[0]-bt[0];

	for(int i = 1;i<n;i++){
		ct[i] = ct[i-1]+bt[i];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}
	float averageWT = 0;
    float averageTAT = 0;
	printf("\nProcess ArrivalTime BurstTime TurnAroudTime WaitingTime completion time\n");

	for(int i  = 0;i<n;i++){
		averageTAT += tat[i];
        averageWT += wt[i];
		printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\n",i+1,at[i],bt[i],tat[i],wt[i],ct[i]);
	}
    printf("average waiting time = %.2f\n", averageWT/n);
    printf("average turnaround time = %.2f\n", averageTAT/n);
}
