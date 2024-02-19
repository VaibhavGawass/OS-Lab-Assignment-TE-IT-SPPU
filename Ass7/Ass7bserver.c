#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){

	int shmid;
	void *shm;
	char *str;
	key_t key =4573;
	
	shmid = shmget(key,1024,0666 | IPC_CREAT);
	
	shm = shmat(shmid,NULL,0);
	str = (char *)shm;
	
	printf("Enter the Message for Client:\n");
	fgets(str,100,stdin);
	
	printf("\nThis is the message :\n%s",str);
	
	shmdt(shm);
	sleep(3);
	printf("\n\nServer Terminatted Successfully!! \n");
}



/*
#include <stdio.h>
#include <sys/shm.h>


int main() {

    void *shm;
    char *shared_memory; // Corrected the variable name
    int shmid;
    key_t key =2345;
    
    // Create or access the shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);

    // Attach to the shared memory
    shm = shmat(shmid, NULL, 0);
    shared_memory = (char *)shm; // Cast to the appropriate data type

    printf("Process attached at %p\n", shared_memory);
    printf("Enter some data to write to shared memory: ");
    fgets(shared_memory, 1024, stdin); // Use fgets to read a line

    printf("You wrote: %s", shared_memory);

    // Detach from the shared memory (not shown in the original code)
    shmdt(shm);

    return 0;
}
*/

