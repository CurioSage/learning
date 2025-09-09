/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 6

struct stack
{
    char data[MAX];
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

void PUSH(stack *ps,char num)
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
int match(char a,char b)
{
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}
int check(char exp[] )
{
       stack s;
       s.top=-1;
        int i;
        char temp;
        for(i=0;i<strlen(exp);i++)
        {
                if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        PUSH(&s,exp[i]);
                if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                        if(s.top==-1)    /*stack empty*/
                        {
                                printf("Right parentheses are more than left parentheses\n");
                                return 0;
                        }
                        else
                        {
                                temp=POP(&s);
                                if(!match(temp, exp[i]))
                                {
                                        printf("Mismatched parentheses are : ");
                                        printf("%c and %c\n",temp,exp[i]);
                                        return 0;
                                }
                        }
        }
        if(s.top==-1) /*stack empty*/
        {
                printf("Balanced Parentheses\n");
                return 1;
        }
        else
        {
                printf("Left parentheses more than right parentheses\n");
                return 0;
        }
}

/*End of match()*/
int main()
{
    
	char str[] = "(A+B))";

	check(str);

	return 0;
}






