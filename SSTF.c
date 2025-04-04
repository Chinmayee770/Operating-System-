#include<stdio.h>
#include<stdlib.h>

int main()
{
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    
    // Logic for SSTF disk scheduling
    
    // Loop will execute until all processes are completed
    while(count != n)
    {
        int min = 1000, d, index;
        for(i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if(min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMovement = TotalHeadMovement + min;
        initial = RQ[index];
        // 1000 is for max
        // You can use any number
        RQ[index] = 1000;
        count++;
    }
    
    printf("Total head movement is %d", TotalHeadMovement);
    return 0;
}
