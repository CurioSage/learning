#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[10];
    int id;
    int age;
    long int mobile;
    char address[50];
    struct node*next;
};


struct node*createnode()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("no node created");
        exit(0);
    }
    printf("enter employee data");
    scanf("%s,%d,%d,%d,%s",&newnode->name,&newnode->id,&newnode->age,&newnode->mobile,&newnode->address);
    newnode->next=NULL;
    return newnode;
}


struct node* insert_rear(struct node* root)
{
    struct node*temp,*newnode;
    newnode=createnode();
    if(root==NULL)
    {
        return newnode;
    }
    temp=root;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return root;
}
struct node* insert_front(struct node* root)
{
    struct node*temp,*newnode;
    newnode=createnode();
    if(root==NULL)
    {
        return newnode;
    }
    temp=root;
    newnode->next=root;
    newnode=root;
    return root;
}

main(){
    struct node* root = NULL;
    root = insert_rear(root);
}