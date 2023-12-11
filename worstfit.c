#include<stdio.h>
#include<conio.h>
#define MAX 100

int main(){
    int worst_fit =0,block_size[MAX], process_size[MAX],temp_size[MAX];
    int i,j,block,process,allocated=0,ptr=0;
    printf("\nEnter the number of blocks:");
    scanf("%d",&block);
    printf("\nEnter the size of each block:\n");
    for(i=0 ; i<block ; i++){
        printf("\nBlock %d ->",(i+1));
        scanf("%d",&block_size[i]);
        temp_size[i] = block_size[i];
    }
    printf("\nEnter the number of processes:\n");
    scanf("%d",&process);
    for(i=0; i<process ; i++){
        printf("\nProcess %d ->",(i+1));
        scanf("%d",&process_size[i]);

    }
    printf("\n***Memory Blocks***\n");
    for(i=0 ; i<block ; i++){
        printf(" | %d |",block_size[i]);
    }
    printf("\n***Process**\n");
    for(i=0 ; i< process ; i++){
        printf("| %d |",process_size[i]);
    }


    for(i=0 ; i<process ; i++){
        worst_fit = 0;
        ptr =-1;
        for(j=0 ; j<block ; j++){
            if(temp_size[j] == block_size[j]){
                if((worst_fit <=(temp_size[j]- process_size[i]))&& (temp_size[j]- process_size[i])>=0){
                    worst_fit = temp_size[j]- process_size[i];
                    ptr = j;
                }
            }
        }
        block_size[ptr]-=process_size[i];
        if(ptr!=-1) 
            printf("\nProcess %d allocated to Block %d",(i+1),(ptr+1));
        else
            printf("\nProcess %d not allocated",(i+1));

    }

    printf("\n\n***Memory Blocks***\n");
    for(i=0;i<block;i++){
        printf("| %d |",block_size[i]);
    }





    return 0;
}