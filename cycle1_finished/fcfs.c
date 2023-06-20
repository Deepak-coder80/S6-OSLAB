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
	int at[n],bt[n],ct[n],wt[n],tat[n],pid[n],p[n];
	
	for(int i =0;i<n;i++){
		// take arrival time and burst time
		printf("Enter arrival time of  process %d:",i+1);
		scanf("%d",&at[i]);
		printf("Enter  burst time of  process %d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}

	// sort in the basis of arrival time
	for(int i =0;i<n-1;i++){
		for(int j = 0;j<n-1-i;j++){
			if(at[j]>at[j+1]){
				int temp = at[j];
				at[j] = at[j+1];
				at[j+1]=temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1]=temp;
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;			
			}		
		}
	}
	
	ct[0] = bt[0]+at[0];
	tat[0] = ct[0]-at[0];
	wt[0] = tat[0]-bt[0];

	for(int i = 1;i<n;i++){
		ct[i] = ct[i-1]+bt[i];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}

	printf("\nProcess ArrivalTime BurstTime TurnAroudTime WaitingTime completion time\n");

	for(int i  = 0;i<n;i++){
		
		printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\n",p[i],at[i],bt[i],tat[i],wt[i],ct[i]);
	}
}
