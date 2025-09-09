#include <stdio.h>
#include <stdlib.h>
#define size 20

typedef struct stack{
    int a[size];
    int top;
}stack;


int isempty(stack *x){
    if(x->top==-1)
        return -1;
    else
        return 0;
}

int isfull(stack *x){
    if(x->top==size-1)
    return 1;
    else
    return 0;

}

int peek(stack *x){
    if(isempty(x)){
    printf("The stack is empty");
    }
    else{
        printf("The top element is ",x->a[x->top]);
    }
}

inte pop(stack *x){
    int temp;
    if(isempty(x)){
    printf("The stack is empty");
    }
    else{
        temp=x->a[x->top];
        x->top--;
        
    }
    return temp; 
}

int push(stack *x, int data){
    if(isfull(x)){
    printf("The stack is Full");
    }
    else{
        x->top++;
        x->a[x->top]=data;
    }
}

void display(stack *x){
    if(isempty(x)){
    printf("The stack is empty");
    }
    else{
        int i;
        for(i=x->top;i>=0;i--){
            printf("\nThe data is %d\n",x->a[i]);
        }
    }    
}

int main(){
    int choice,temp,data;
    stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top= -1;
    int a[20];
    while(1){

    printf("Enteerr the choice\n1-Push\n2-pop\n3-display\n4-peek\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 :printf("Enter the Data\n");
        scanf("%d",&data);
        push(s,data);
        break;
        case 2 :temp=pop(s);
        printf("the popped element is %d\n",temp);
        break;
        case 3 :display(s);
        break;
        case 4 : peek(s);
        break;
        default :printf("Enter the correct choice\n");
        break;
}
}

}