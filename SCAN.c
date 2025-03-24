#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100], i, n, TotalHeadMovement=0, initial, count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);

    int maxCylinders=200;
    int direction=1;

    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                int temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }

    while(count!=n){
        for(i=0;i<n;i++){
            if((direction==1&&RQ[i]>=initial)||(direction==-1&&RQ[i]<=initial)){
                TotalHeadMovement+=abs(RQ[i]-initial);
                initial=RQ[i];
                RQ[i]=maxCylinders+1;
                count++;
            }
        }

        direction*=-1;
    }

    printf("Total head movement is %d\n",TotalHeadMovement);
    return 0;
}
