#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

 
void insertion(int a[] ,int n){
	int i,j,key;
	for ( i=1 ; i<n ; i++){
		key = a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void bubble(int a[] ,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void printArray(int a[] ,int n){
	int i;
	
	for(i=0; i<n ;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int main(){

	int i,n,pid;
	printf("Enter Size of array\n");
	scanf("%d",&n);
        int arr[n];
        printf("Enter the elements of array");
        for (i=0 ; i<n ;i++){
        	scanf("%d",&arr[i]);
        	printf("\n");
        }
        
        printf("The inputted Array is :\n");
        printArray(arr ,n);
        
        pid=fork();
        
        if(pid==0){
        	printf("\n-----------------------------\n");
        	printf("This is child process\n");
        	printf("The sorted Array is :\n");
        	bubble(arr,n);
        	printArray(arr ,n);
        	printf("Child Process id is %d",getpid());
        	printf("\nChilds Parent Process id is %d",getppid());
        	printf("\n-----------------------------\n");
        	
        }
        else if(pid==-1){
        	printf("Child Process is not created\n");
        }
        else{   
        	sleep(3);
        	
        	printf("\n-----------------------------\n");
        	printf("This is parent process\n");
        	printf("The sorted Array is :\n");
        	insertion(arr,n);
        	printArray(arr ,n);
        	printf("Parent Process id is %d",getpid()); 
        	printf("\n-----------------------------\n");
        	system("ps -aux");
        }   
}


