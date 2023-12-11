#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
    int i, req[100],d,n,sum=0;
    printf("Enter the number of requests:\n");
    scanf("%d",&n);
    printf("Enter the requests:");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the write/read head:");
    scanf("%d",&d);

    for(i=0;i<n;i++){
        sum= sum  + abs(req[i]-d);
        d= req[i];
    }
    printf("Overheadtime= %d",sum);
    return 0;
}

