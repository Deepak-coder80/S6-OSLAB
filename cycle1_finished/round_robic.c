#include<stdio.h>

void main(){

	int n,i,qt,temp,bt[10],wt[10],tat[10],rem_bt[10];
	int count = 0,sq=0;
	float awt=0,atat=0;

	printf("Enter number of process ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter burst time of process %d : ",(i+1));
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];			
	}

	printf("Enter Time Quantum ");
	scanf("%d",&qt);

	while(1){
		for(i=0,count=0;i<n;i++){
			temp = qt;
			if(rem_bt[i] == 0){
				// process completed
				
				count++;
				continue;
				
			}
			if(rem_bt[i]>qt){
				rem_bt[i] -= qt;
				printf("process %d executed\n",(i+1));
		
			}else{
				if(rem_bt[i] >=0){
					temp = rem_bt[i];
					rem_bt[i] = 0;
					
					printf("process %d completed\n",(i+1));				
				}		
			}
			sq += temp;
			tat[i] = sq;
					
		}
		if(n == count){
			break;
		}	
	}

	printf("\nProcess\tBurst Time\tTurnaround time\tWaiting Time\n");
	for(i = 0;i<n;i++){
		wt[i] = tat[i] -bt[i];
		awt += wt[i];
		atat +=	tat[i];
		printf("\n%d\t\t%d\t\t%d\t%d",(i+1),bt[i],tat[i],wt[i]);
	}

	awt /=n;
	atat /=n;
	printf("\nAverage Wating time %.2f",awt);
	printf("\nAverage Turn Around  time %.2f\n",atat);

}