#include<stdio.h>
#include<stdlib.h>

struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
    printf("Node not available");
    exit(0);
}

printf("enter the data");
scanf("%d",&newnode->data);
newnode->next=newnode;

struct node* insert_rear(struct node* root)
{
    struct node* temp,*newnode;
    newnode=createnode();
    if(newnode==NULL)
    return newnide
}