#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next, *prev;
};
struct node * head= NULL;
struct node * tail= NULL;
void createlist(int n){
    struct node *newnode;
    int i, data;
    for(i=1;i<=n;i++){
        printf("\nEnter the data for node %d: ",i);
        scanf("%d",&data);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->prev=newnode->next=NULL;
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
}
void InsertAtLeft(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    if (head==NULL){
        head=tail=newnode;
    }else{
        head->prev=newnode;
        head=newnode;
    }
}
void InsertAtLast(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=tail;
    newnode->next=NULL;
    if (tail==NULL){
        head=tail=newnode;
    }else{
       tail->next=newnode;
       tail=newnode;
    }
}
void DeleteByValue(int value){
    struct node *temp=head;
    if(head==NULL){
        printf("The List is Empty!\n");
        return;
    }
    while(temp!=NULL && temp->data!=value){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nValue not found!");
        return;
    }
    if(temp==head){
        struct node * temp;
        if(head==NULL){
            printf("List is Empty!.\n");
            return;
        }
        temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }else{
            tail=NULL;
        }
        free(temp);

    }else if(temp==tail){
        struct node * temp;
        if(tail==NULL){
            printf("List is empty.\n");
            return;
        }
        temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }else{
            head=NULL;
            free(temp);
        }
    }else{
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
void display(){
    struct node *temp = head;
    if (head == NULL){
        printf("List is empty.");
    }
    else{
        printf("Linked List:\n");
        while (temp != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
}
void main(){
    int ch, value,n,data;
    do{
        printf("\n1)Create linked list 2)Insert at Left 3)Insert at end 4)Delete by value 5)Display list");
        printf("\nEnter -1 to exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                createlist(n);
                break;
            case 2:
               
                printf("\nEnter the Data to insert: ");
                scanf("%d", &data);
                InsertAtLeft(data);
                break;
            case 3:
               
                printf("\nEnter the Data to insert: ");
                scanf("%d", &data);
                InsertAtLast(data);
                break;
            case 4:
                printf("Enter Value: ");
                scanf("%d",&value);
                DeleteByValue(value);
                break;
            
            case 5:
                display();
                break;
            default: printf("Invalid input.");
        }
    }while(ch != -1);
}
