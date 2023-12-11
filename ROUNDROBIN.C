#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){

    int i,NOP,sum=0,count= 0, remainingProcess,quant,wt=0,tat=0,at[10],bt[10],temp[10];
    float avg_wt,avg_tat;

    printf("Total number of processes in the system :");
    scanf("%d",&NOP);
    remainingProcess = NOP;

    printf("\nEnter the arrival and burst time of Processes\n");
    for(i=0; i< NOP ; i++){
        printf("Process %d->",i+1);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        temp[i]= bt[i];
    }

   printf("\nEnter the time quantum for the processes:") ;
   scanf("%d",&quant);
   printf("Process No \t Burst Time \t TAT \tWaiting Time");
   for(sum = 0, i=0 ; remainingProcess != 0;){
    if(temp[i] <= quant &&  temp[i]>0){
        sum += temp[i];
        temp[i] = 0;
        count =1;
    }
    else if(temp[i]> 0){
        temp[i] -= quant;
        sum += quant;
    }
    if(temp[i]== 0 && count ==1){
        remainingProcess--;
        printf("\nProcess No[%d] \t %d\t\t %d\t\t %d",i+1,bt[i],sum-at[i],sum- at[i]- bt[i]);
        wt += sum - at[i]- bt[i];
        tat += sum - at[i];
        count =0;
    }
    if(remainingProcess !=0){
        if(i== NOP -1)
            i=0;
        else if (at[i+1]<= sum)
            i++;
        else if (at[i] > sum)
            i=0;
    }
   }

   avg_tat = wt*1.0/NOP;
   avg_wt = wt*1.0/NOP;

   printf("\nAvg TAT %f",avg_tat);
   printf("\n Avg WT %f",avg_wt);

   return 0;

}