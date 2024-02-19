
#include<stdio.h>
#include<stdlib.h>

int scan(){
        int RQ[100], i, j, n, THM = 0, head, size, direct;
        printf("Enter the number of Requests\n");
        scanf("%d", &n);
        printf("Enter the Requests sequence\n"); 
        for (i = 0; i < n; i++) {
            scanf("%d", &RQ[i]);
        }
        printf("Enter head head position\n");
        scanf("%d", &head); 
        printf("Enter total number of tracks \n"); 
        scanf("%d", &size);
        printf("Enter the head movement direction as for high 1 and for low 0\n");
        scanf("%d", &direct);
        for (i = 0; i < n; i++){
            for (j = 0; j < n - i - 1; j++){
                if (RQ[j] > RQ[j + 1]){
                    int temp;
                    temp = RQ[j];
                    RQ[j] = RQ[j + 1]; 
                    RQ[j + 1] = temp;
                }
            }
        }
        int index;
        for (i = 0; i < n; i++){
            if (head < RQ[i]){
                index = i;
                break;
            }
        }
        if (direct == 1){
           for (i = index; i < n; i++){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];                   
            }
            THM = THM + abs(size - RQ[i - 1] - 1);
            head = size - 1;
            for (i = index - 1; i >= 0; i--){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
        }
        else{
            for (i = index - 1; i >= 0; i--) {
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
            THM = THM + abs(RQ[i + 1] - 0);
            head = 0;
            for (i = index; i < n; i++){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
        }
        printf("Total head movement is %d\n", THM);
        return 0;
}

int main(){
	
	scan();
	return 0;	
	
}
    
    
