#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL,*head1=NULL, *head2=NULL;

void createList(struct node **head,int n){
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
        if (*head== NULL){
            *head= newnode;
        }
        else{
            temp -> next = newnode;
        }
        temp = newnode;
    }
    printf("Linked list is created.");

}
void display(struct node *head){
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


void bubblesort(struct node * head){
    struct node *i, *j;
    int tempdata;

    if(head == NULL)
        return;

    for(i = head; i->next != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                tempdata = i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }

    printf("Linked List Sorted Successfully!\n");
}

struct node * ReverseLinkedList(struct node * head){
    struct node * prev=NULL, *next=NULL,* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev= curr;
        curr= next;
    }
    printf("Linked List reversed Successfully!.\n");
    return prev;
}

struct node * concat(struct node * head1, struct node * head2){
    struct node * temp;
    if(head2==NULL){
        return head1;
    }
    if(head1==NULL){
        return head2;
    }
    temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    printf("Linked Lists Concatenated Successfully!.\n");
    return head1;


}

void main(){
    int n, ch, listchoice;
    do{
       
        printf("\n1)Create LL 2)Sort LL 3)Reverse the LL 4)Concat LL's 5)Display LL ");
        printf("\nEnter -1 to exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("\nEnter the listchoice(1 or 2):");
                scanf("%d",&listchoice);
                printf("\nEnter no. of nodes:");
                scanf("%d",&n);
                if(listchoice==1){
                    createList(&head1,n);
                }else if(listchoice==2){
                    createList(&head2, n);
                }else{
                    printf("\nInvalid Choice");
                }
                break;
            case 2:
                printf("\nEnter the listchoice(1 or 2):");
                scanf("%d",&listchoice);
                if(listchoice==1){
                    bubblesort(head1);
                }else if(listchoice==2){
                    bubblesort(head2);
                }else{
                    printf("\nInvalid Choice");
                }
                break;
            case 3:
                printf("\nEnter the listchoice(1 or 2):");
                scanf("%d",&listchoice);
                if(listchoice==1){
                    head1=ReverseLinkedList(head1);
                }else if(listchoice==2){
                    head2=ReverseLinkedList(head2);                    
                }else{
                    printf("\nInvalid Choice");
                }
                break;
            case 4:
                head1=concat(head1, head2);
                break;
            case 5:
                printf("\nList 1\n");
                display(head1);
                printf("\nList 2\n");
                display(head2);
                break;
            default: printf("Invalid input.");
        }
    }while(ch!=-1);
   
}
