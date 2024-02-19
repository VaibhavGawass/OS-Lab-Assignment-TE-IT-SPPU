#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(){

	int fd1,fd2,l=1,w=0,c=0,i=0,j=0;
	char * fifo1 ="file1";
	char * fifo2 ="file2";
	FILE *fp;
	char buf[200],ch[200];
	
	fd1=open(fifo1,O_RDONLY);
	read(fd1,buf,sizeof(buf));
	printf("Data from Process 1:\n%s",buf);
	
	while( buf[i] != '\0')
	{
		if(buf[i]=='\n'){
			l++;
		}
		else if(buf[i] == ' '){
			w++;
		}
		else{
			c++;
		}
		i++;
	}
	
	printf("\nTotal Number of Lines: %d\n",l);
	printf("\nTotal Number of words: %d\n",w);
	printf("\nTotal Number of characters: %d\n",c);
	
	fp=fopen("test.txt","w");
	fprintf(fp,"\nTotal Number of Lines: %d\n",l);
	fprintf(fp,"\nTotal Number of words: %d\n",w);
	fprintf(fp,"\nTotal Number of characters: %d\n",c);
	fclose(fp);
	
	fp=fopen("test.txt","r");
	
	while( !feof(fp)){
		ch[j]=fgetc(fp);
		j++;
	}
	fclose(fp);
	
	close(fd1);
	
	fd2=open(fifo2,O_WRONLY);
	write(fd2,ch,strlen(ch)+1);
	close(fd2);
	return 0;
}
