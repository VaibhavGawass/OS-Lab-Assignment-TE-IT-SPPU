#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t wr,mutex;
int a=0;
int readercount=0;
void * reader(void * args){
	long int num=(long int)args;
	
	pthread_mutex_lock(&mutex);
		readercount++;
	pthread_mutex_unlock(&mutex);
	
	if(readercount==1)
		pthread_mutex_lock(&wr);
	
	printf("\nReader  %ld is in Critical section",num+1);
	printf("\nReader %ld has read %d",num+1,a);
	
	pthread_mutex_lock(&mutex);
		readercount--;
	pthread_mutex_unlock(&mutex);
	
	if(readercount==0)
		pthread_mutex_unlock(&wr);
	printf("\nReader  %ld has left Critical section",num+1);
}

void * writer(void * args){
	
	long int num=(long int)args;
	
	pthread_mutex_lock(&wr);
		printf("\nWriter %ld is in Critical section",num+1);
		printf("\nWriter %ld has written %d",num+1,++a);
	pthread_mutex_unlock(&wr);
	printf("\nWriter  %ld has left Critical section",num+1);
}


int main(){
	int nr,nw;
	pthread_t r[10],w[10];
	unsigned long int i,j,k,l;
	
	pthread_mutex_init(&wr,NULL);
	pthread_mutex_init(&mutex,NULL);
	
	printf("Enter the number of Reader: \n");
	scanf("%d",&nr);
	printf("Enter the number of writer: \n");
	scanf("%d",&nw);
	
	
	for(i=0;i<nr;i++)
		pthread_create(&r[i],NULL,reader,(void *)i);
		
	for(j=0;j<nw;j++)
		pthread_create(&w[j],NULL,writer,(void *)j);
	
	for(k=0;k<nr;k++)
		pthread_join(r[k],NULL);
	
	for(l=0;l<nw;l++)
		pthread_join(w[l],NULL);
	return 0;
}
