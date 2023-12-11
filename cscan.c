#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
    int i,req[100],n,d,l,h,sum=0,min,max,flag,loc=0;
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
    req[n]= d;
    for(i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(req[j]>req[j+1]){
                int temp;
                temp= req[j];
                req[j]= req[j+1];
                req[j+1]= temp;

            }
        }
    }
    for(i=0;i<(n+1);i++){
        if(req[i]==d){
            loc=i;
            break;
        }
    }
    printf("\nEnter the direction in which it is moving: (Lower:1 Higher:0)");
    scanf("%d",&flag);
   
    if(flag==1){
        sum= abs(d-l)+abs(l-h)+ abs(h-req[loc+1]);
    }
    else if(flag == 0){
        sum= abs(d-h)+ abs(h-l)+ abs(req[loc-1]);
    }
    printf("Overheadtime: %d",sum);





return 0;
}