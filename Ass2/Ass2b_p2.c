#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
   int i;
   int length=strlen(argv[1]);
   printf("Program 2 prints array in reverse order :\n");
   for(i=length-1;i>=0;i--)
   {
      printf("%d  ",argv[1][i]-48);
   }
   printf("\n");
   
}

