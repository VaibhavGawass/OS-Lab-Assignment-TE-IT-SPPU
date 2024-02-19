
#include<stdio.h>
#include<stdlib.h>

void sstf(){
	
	int i,n,head,THM=0,count=0;
	int rq[100];
	
	printf("Enter the number of request:\n");
	scanf("%d",&n);
	
	printf("\nEnter the request sequence\n");
	
	for(i=0;i<n;i++){
		scanf("%d",&rq[i]);
	}
	
	printf("Enter the current head position:\n");
	scanf("%d",&head);
	
	while(count != n){
		int min=1000,d,index;
		for(i=0;i<n;i++){
			d= abs( rq[i] - head );
			
			if(d<min){
				min =d;
				index =i;
			}
		}
		
		THM =THM + min;
		
		head=rq[index];
		rq[index]=1000;
		count++;
	}
	
	printf("\nThe Total Head Movement is %d \n",THM);
	
}

int main(){
	
	sstf();
	return 0;	
	
}
