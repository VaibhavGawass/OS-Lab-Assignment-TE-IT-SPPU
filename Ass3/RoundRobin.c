#include<stdio.h>


void main(){

	int i,NOP,y,quant,wt=0,tat=0;
	int sum=0,count=0;
	int at[10],bt[10],temp[10];
	float avg_wt,avg_tat;
	
	printf("Enter number of process:\n");
	scanf("%d",&NOP);
	y=NOP;
	
	for (i=0;i<NOP;i++){
		printf("Enter the Arrival Time and Burst Time for Process[%d]",i+1);
		printf("\nEnter the Arrival Time:\t");
		scanf("%d",&at[i]);
		printf("\nEnter the Burst Time:\t");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	
	printf("\nEnter the time quantum:\n");
	scanf("%d",&quant);
        
        printf("\nProcess No  \t\t Burst Time\t\t TAT\t\tWaiting Time");
        
        for(sum=0,i=0; y!=0;){
        	
        	if(temp[i] <= quant && temp[i] > 0){
        		sum = sum + temp[i];
        		temp[i]=0;
        		count=1;
        	}
        	else if(temp[i] > 0){
        		temp[i] = temp[i] - quant;
        		sum = sum + quant;
        	}
        	if(temp[i] == 0 && count ==1){
        		y--;
        		printf("\nProcess No[%d]\t\t %d\t\t\t %d \t\t%d",i+1,bt[i],sum-at[i],(sum-at[i])-bt[i]);
        		wt=wt+((sum-at[i])-bt[i]);
        		tat=tat+(sum-at[i]);
        		count=0;
        	}
        	if(i == NOP-1){
        		i=0;
        	}
        	else if(at[i+1]<=sum){
        		i++;
        	}
        	else{
        		i=0;
        	}	
        }
        
        avg_wt = wt*1.0/NOP;
        avg_tat = tat*1.0/NOP;
        printf("\nThe average Waiting Time is:  %f",avg_wt);
        printf("\nThe average Turnaround Time is:  %f\n",avg_tat);
}
