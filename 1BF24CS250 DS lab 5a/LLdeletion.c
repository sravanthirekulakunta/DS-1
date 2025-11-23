#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void createList(int n){
    struct node *newnode, *temp;
    int data, i;
    if (n<0){
        printf("n should be greater than 0.");
        return;
    }
    for(i=1; i<=n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("Memory alloction failed.");
            return;
        }
        printf("Enter data:");
        scanf("%d",&data); 
        newnode -> data = data;
        newnode -> next = NULL;
        if (head == NULL){
            head = newnode;
        }
        else{
            temp -> next = newnode;
        }
        temp = newnode;
    }
    printf("Linked list is created.");

}

void deletefirst(){
    struct node *temp;
    if (head==NULL){
        printf("List is Empty! Nothing to delete");
        return;
    }
    temp=head;
    head=head->next;
    printf("The Deleted element is %d", temp->data);
    free(temp);
}
void deletelast(){
    struct node *temp, *prev;
    if(head==NULL){
        printf("The Linked list is empty!");
        return;
    }
    if (head->next==NULL){
        printf("Deleted element: %d", head->data);
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("Deleted element : %d", temp->data);
    free(temp);
}
void deletespecific(int value){
    struct node *temp=head, *prev=NULL;
    if(head==NULL){
        printf("The list is empty!");
        return;
    }
    if(head->data==value){
        deletefirst();
        return;
    }
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Value not found!!");
        return;
    }
    prev->next=temp->next;
    free(temp);
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

int main(){
    int ch, value,n;
    do{
        printf("\n1)Create linked list 2)Delete at beginning 3)Delete at any position 4)Delete at end 5)Display list");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                deletefirst();
                break;
            case 3:
                printf("Enter Value: ");
                scanf("%d",&value);
                deletespecific(value);
                break;
            case 4:
                deletelast();
                break;
            case 5:
                display();
                break;
            default: printf("Invalid input.");
        }
    }while(ch != -1);
}