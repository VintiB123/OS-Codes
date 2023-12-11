#include<stdio.h>
#include<conio.h>

int main(){
    int i,req[100],n,d,l,h,sum=0,min,max,flag;
    printf("Enter the number of requests: \n");
    scanf("%d",&n);
    printf("\nEnter the range:");
    printf("\nLower Limit:");
    scanf("%d",&l);
    printf("\nUpper Limit:");
    scanf("%d",&h);
    printf("\nEnter requests:");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the read write head:");
    scanf("%d",&d);
    printf("\nEnter the direction in which it is moving: (Lower:1 Higher:0)");
    scanf("%d",&flag);
    min= req[0];
    max= req[0];

    for(i=0;i<n;i++){
        if(req[i]>max)
        {
            max= req[i];
        }
        if(req[i]<min)
        {
            min= req[i];
        }
    }
    if(flag==1){
        sum= abs(d-l) + abs(max-l);
    }
    else if(flag == 0){
        sum= abs(d-h)+ abs(h-min);
    }
    printf("Overheadtime: %d",sum);





return 0;
}