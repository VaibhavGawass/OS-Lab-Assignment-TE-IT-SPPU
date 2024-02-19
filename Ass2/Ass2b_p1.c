#include <stdio.h>
#include <string.h>
#include <unistd.h>

void bubble_asc(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nProcess 1 sorted Array :");
    for (i = 0; i < n; i++)
    {
        printf("  %d", arr[i]);
    }
}

int main(int argc,char *argv[])
{
   int n,i,pid;
   printf("Enter the number of elements : ");
   scanf("%d",&n);
   int num[n];
   
   char *newargv[10];
   char charArray[100];
   char temp[50];
   
   for(i=0;i<n;i++)
   {
      printf("Enter element no. %d :",i+1);
      scanf("%d",&num[i]);
   }
   bubble_asc(num,n);
   for(i=0;i<n;i++)
   {
      sprintf(temp,"%d",num[i]);
      strcat(charArray,temp);
   }
   
   
   newargv[0]=argv[1];
   newargv[1]=charArray;
   newargv[2]=NULL;
   
   pid=fork();
   
   if(pid==-1)
   {
      printf("Error on fork\n");
   }
   
   if(pid==0)
   {
      execve(argv[1],newargv,NULL);
      printf("\nThis text will not be printed as the execve() call has replaced currnet process image to process 2 image\n");
   }
   else if(pid>0)
   {
      printf("\nParent process executing parallel to child\n");
   }
   return 0;
}

