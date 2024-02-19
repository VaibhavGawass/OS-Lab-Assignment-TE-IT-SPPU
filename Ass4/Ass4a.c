#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t empty,full;
pthread_mutex_t mutex;
int buf[5];
int count=0;

void * producer( void * args){
	
	long int num = (long int )args;
	
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	
	buf[count]=count;
	printf("\nProducer %ld has produced %d\n",num+1,buf[count]);
	count++;
	
	//sleep(1);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void * consumer( void * args){
	
	long int num = (long int )args;
	
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	
	count--;
	printf("\nConsumer %ld has consumed %d\n",num+1,buf[count]);

	//sleep(1);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

int main(){
	
	int np,nc;
	pthread_t p[10],c[10];
	unsigned long int i,j,k,l;
	
	printf("Enter the number of producer:\n");
	scanf("%d",&np);
	printf("Enter the number of consumer:\n");
	scanf("%d",&nc);
	
	sem_init(&empty,0,5);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	
	for(i=0;i<np;i++)
		pthread_create(&p[i],NULL,producer,(void *)i);
	
	for(j=0;j<nc;j++)
		pthread_create(&c[j],NULL,consumer,(void *)j);
		
	for(k=0;k<np;k++)
		pthread_join(p[k],NULL);
		
	for(l=0;l<nc;l++)
		pthread_join(c[l],NULL);
	
}
