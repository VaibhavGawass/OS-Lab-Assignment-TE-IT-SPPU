#include<stdio.h>
#include<sys/shm.h>

int main(){

	int shmid;
	void *shm;
	char *str;
	key_t key =4573;
	
	shmid = shmget(key,1024,0666);
	
	shm = shmat(shmid,NULL,0);
	str = (char *)shm;
	
	printf("\nThis is the message from Server :\n%s",str);
	
	shmdt(shm);
	
	shmctl(shmid,IPC_RMID,NULL);
	printf("\n\nClient Terminatted Successfully!! \n");
	
	
}











/*

#include <stdio.h>
#include <sys/shm.h>


int main() {

    void *shm;
    char *shared_memory; // Corrected the variable name
    int shmid;
    key_t key = 2345;

    // Access the existing shared memory segment
    shmid = shmget(key, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);S

    // Attach to the shared memory
    shm = shmat(shmid, NULL, 0);
    shared_memory = (char *)shm; // Cast to the appropriate data type

    printf("Process attached at %p\n", shared_memory);
    printf("Data read from shared memory is: %s\n", shared_memory);

    // Detach from the shared memory (not shown in the original code)
    shmdt(shm);

    return 0;
}
*/
