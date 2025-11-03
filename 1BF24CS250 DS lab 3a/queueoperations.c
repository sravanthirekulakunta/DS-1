#include <stdio.h>
#include <ctype.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enque(int x){
    
    if(rear==(N-1)){
        printf("Queue Overflow\n");
    }
    else if ((front==-1)&&(rear==-1)){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void deque(){
    if ((front==-1)&&(rear==-1)){
        printf("The Queue is empty\n");
    }else if((front==rear)){
        printf("Deleted element is: %d",queue[front]);
        front=rear=-1;
    }else{
        printf("Deleted element is: %d",queue[front]);
        front++;
    }
}
void display(){
    int i;
    if ((front==-1)&&(rear==-1)){
        printf("The Queue is empty\n");
    }else{
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    }
}
void main(){
    int ch, y;
    do{
        printf("\nEnter your choice between 1 to 4: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the element you want to insert:");
                scanf("%d",&y);
                enque(y);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Your choice is invalid!");
        }
    }while(ch!=4);

}