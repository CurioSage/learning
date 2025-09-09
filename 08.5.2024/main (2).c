/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10

struct stack
{
    float data[MAX];
    int top;
};

typedef struct stack stack;

int full(stack s)
{
    if(s.top==MAX-1)
        return(1);
    else
        return(0);
}

int empty(stack s)
{
    if(s.top==-1)
        return(1);
    else
        return(0);
}

void PUSH(stack *ps, float num)
{
    if(full(*ps))
    {
        printf("\nStack Overflow!!");
        return;
    }
    ps->top++;
    ps->data[ps->top]=num;
    return;
}

float POP(stack *ps)
{
    float temp;

    if(empty(*ps))
    {
        printf("\nStack Underflow!!");
        return(-1);
    }
    temp=ps->data[ps->top];
    ps->top--;
    return(temp);
}


int eval(char postfix[])
{
    stack s;
    int op1,op2,res;
    int i;
    char ch;
    s.top=-1;

    for(i=0; i<strlen(postfix); i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            PUSH(&s,ch-'0');
        }
        else if(ch=='+' ||ch=='-'||ch=='*'||ch=='/' )
        {
            op2=POP(&s);
            op1=POP(&s);
            
        switch(ch)
        {
        case '+': res=op1+op2;break;
        case '-': res=op1-op2;break;
        case '*': res=op1*op2;break;
        case '/': res=op1/op2;break;
        default : printf("\nIllegal Operation");
                    exit(1);
        }
            PUSH(&s,res);
        }
    }
    res=POP(&s);
    return(res);
}

int main()
{
    char postfix[MAX];
    int res;

    printf("\nEnter the postfix string:");
    scanf("%s",postfix);

    printf("\nThe original postfix expression is: %s",postfix);

    res=eval(postfix);
    printf("\nThe value of postfix expression is:%d",res);

    return 0;
}






