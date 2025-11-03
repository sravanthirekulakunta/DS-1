#include <stdio.h>
#define N 5
int queue[N];
int front=-1, rear=-1;
void enqueue(int x){
    if ((front==0&& rear==N-1)||(front==rear+1)){
        printf("The Queue is Full\n");
    }
    else if(front==-1&& rear==-1){
        front=rear=0;
        queue[rear]=x;

    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1&& rear==-1){
        printf("The Queue is Empty!\n");
    }
    else if(front==rear){
        printf("The deleted element is %d\n", queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("The deleted element is %d\n", queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if(front==-1&& rear==-1){
        printf("The Queue is Empty!\n");
    }else{
        int i=front;
        printf("The Queue is:\n");
        while(i!=rear){
            printf("%d\n",queue[i]);
            i=(i+1)%N;
        }printf("%d\n",queue[rear]);
    }
}
void main(){
    int ch, y;
    do{
        printf("Enter element from 1 to 4 insert, delete, display and stop:");
        scanf("%d",& ch);
        switch(ch){
            case 1:
                
                printf("\nEnter element to insert:");
                scanf("%d", & y);
                enqueue(y);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Your choice is Invalid!");
        }
    }while(ch!=4);
}