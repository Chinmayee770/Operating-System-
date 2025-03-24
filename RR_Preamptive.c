#include<stdio.h>  
#include<conio.h>  

int main()  
{  
    // initialize the variables
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    
    printf("Total number of processes in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; // Assign the number of processes to variable y  

    // Use a loop to enter the details of the processes like Arrival time and the Burst Time  
    for(i = 0; i < NOP; i++)  
    {  
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);  
        printf("Arrival time: ");  // Accept arrival time  
        scanf("%d", &at[i]);  
        printf("Burst time: "); // Accept the Burst time  
        scanf("%d", &bt[i]);  
        temp[i] = bt[i]; // store the burst time in temp array  
    }  

    // Accept the Time Quantum for the process  
    printf("Enter the Time Quantum for the process: ");  
    scanf("%d", &quant);  

    // Display the Process No, Burst Time, Turn Around Time, and the Waiting Time  
    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  

    for(sum = 0, i = 0; y != 0;)  
    {  
        if(temp[i] <= quant && temp[i] > 0) // define the conditions   
        {  
            sum += temp[i];  
            temp[i] = 0;  
            count = 1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] -= quant;  
            sum += quant;    
        }  

        if(temp[i] == 0 && count == 1)  
        {  
            y--; //decrement the process no.  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);  
            wt += sum - at[i] - bt[i];  
            tat += sum - at[i];  
            count = 0;     
        }  

        if(i == NOP - 1)  
            i = 0;  
        else if(at[i + 1] <= sum)  
            i++;  
        else  
            i = 0;  
    }  

    // Calculate the average waiting time and Turn Around time  
    avg_wt = wt * 1.0 / NOP;  
    avg_tat = tat * 1.0 / NOP;  

    printf("\nAverage Turn Around Time: \t%f", avg_wt);  
    printf("\nAverage Waiting Time: \t%f", avg_tat);  

    getch();  

    return 0;
}  
