# include <stdio.h>
# define N 5
 int stack[N];
 int top=-1;
 int i;

void push(){
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if (top==N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=x;
        printf("Now the top is:%d \n",top);
        printf("The  elements Stack are:");
        for(i=top;i>=0&&i<N;i--){
            printf("%d, ",stack[i]);
        }
    }
    }
    void pop(){
        int item;
        if(top==-1){
            printf("Underflow");
        }
        else{
            item=stack[top];
            top--;
            printf("%d is popped",item);
            printf("\nThe  elements Stack are:");
            for(i=top;i>=0&&i<N;i--){
                printf("%d",stack[top]);
            }
        }
    }
    void peek(){
        if (top==-1){
            printf("Underflow");
        
        }
        else{
            printf("%d", stack[top]);
        }
    }
    void main(){
    int stack[5];
    int top=-1;
    int a;
    do{
        printf("\nEnter 1,2,3 to choose push,pop,peek operations respectively");
        scanf("%d",&a);
        switch(a){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            default:
                printf("Invalid input!!");
                break;
        }

    }while(a!=-1);
    
} 