#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	
	int fd1,fd2;
	char *fifo1 = "file1";
	char *fifo2 = "file2";
	char buf[1024];
	
	mkfifo(fifo1,0666);
	mkfifo(fifo2,0666);
	
	fd1=open(fifo1,O_WRONLY);
	write(fd1,"Hello Everyone\nToday is last day \nBe ready for Practicals",sizeof("Hello Everyone\nToday is last day \nBe ready for Practicals"));
	close(fd1);
	
	fd2=open(fifo2,O_RDONLY);
	read(fd2,buf,sizeof(buf));
	printf("Data from Process 2\n %s",buf);
	close(fd2);
	return 0;
}
