#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100], i, n, TotalHeadMovement=0, initial, count=0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for(i=0; i<n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    while(count != n){
        for(i=0; i<n; i++){
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
            count++;
        }
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}
