#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int empty= 10, data= 0;

void wait(int *S){
    while(*S<=0);
    (*S)--;
}

void signal(int *S){
    (*S)++;
}

void producer(){

    wait(&empty);
    wait(&mutex);
    data++;
    signal(&mutex);
    signal(&full);
    printf("\nProducer produces item number: %d",data);
}

void consumer(){
    wait(&full);
    wait(&mutex);
    printf("\nConsumer consumes item number: %d",data);
    data--;
    signal(&mutex);
    signal(&empty);
}

int main(){

    int n,i;
    do
    {
        printf("\n1. Enter 1 for Producer"
           "\n2. Enter 2 for consumer"
           "\n3. Exit");

        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if((mutex==1) && (empty!=0)){
                producer();

            }
            else{
                printf("\nBuffer is full, new data cannot be produced");
            }
            break;

        case 2:
            if((mutex==1) && (full!=0)){
                consumer();
            }
            else{
                printf("\nbuffer is empty, cannot consume any more");

            }
            break;

            case 3:
                exit(0);
                break;
        
        default:
            printf("\nEnter valid choice");
            break;
        }
    } while (n!=3);
    
    




return 0;

}