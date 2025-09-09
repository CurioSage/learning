#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct node
{
    char name[100];
    int rollno;
    int sem;
    char d;
    struct node*next;
    struct node*prv;

};
struct node*creatnode()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("node is empty");

    }
     printf("Enter name: ");
    scanf("%s", newnode->name);
    printf("Enter roll no: ");
    scanf("%d", &newnode->rollno);
    printf("Enter sem: ");
    scanf("%d", &newnode->sem);
    printf("Enter div: ");
    scanf(" %c", &newnode->d);
    newnode->next=NULL;
    newnode->prv=NULL;

}
struct node*insertatfront(struct node*root)
{
    struct node*newnode ,*temp;
    newnode=creatnode();
    if(root==NULL)
    {
        return newnode;
    }

    newnode->next=root;
    root->prv=newnode;
    root=newnode;
    return root;

}
struct node*insertatrear(struct node*root)
{
    struct node*newnode,*temp;
    newnode=creatnode();
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
    newnode->prv=temp;
    return root;

};
    int display(struct node*root)
    {
    struct node*temp;
    temp=root;
    while(temp->next!=NULL)
    {

        printf("Students are:\n");
            printf("Roll No: %d Name: %s div:%c sem:%d\n",temp->rollno,temp->name,temp->d,temp->sem);
        temp=temp->next;

    }
    while(temp->prv!=NULL)
    {

        printf("Students are:\n");
            printf("Roll No: %d Name: %s div:%c sem:%d\n",temp->rollno,temp->name,temp->d,temp->sem);
        temp=temp->prv;
    }
    }
int count(struct node*root)
{
    struct node*newnode,*temp;
    temp=root;
    int c=0;
    if(root==NULL)
    {
        printf("list is empty");
    }
    while(temp!=NULL)
    {
        temp = temp->next;
        c++;
    }
    printf("number of nodes is %d\n",c);
    return c;
}


struct node *insertatpos(struct node *root)
{
    struct node *newnode, *temp, *prv;
    int pos, i;
    newnode = create_node();
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1)
    {
        printf("Invalid input\n");
        return root; // Return root without modifying the list
    }
    if (pos == 1)
    {
        root = insert_front(root);
        return root; // Return root after inserting at front
    }
    if (pos == count + 1)
    {
        root = insert_rear(root);
        return root; // Return root after inserting at rear
    }

    temp = root;
    prv = NULL;
    i = 1;
    while (i < pos)
    {
        prv = temp;
        temp = temp->next;
        i++;
    }

    
    prv->next = newnode;
    newnode->prv = prv;
    newnode->next = temp;
    temp->prv = newnode;

    return root; // Return root after insertion at the specified position
}


struct node*deleteatrear(struct node*root){
    struct node*temp;
    if(root==NULL){
    printf("list is empty");
    }
    if(root->next==NULL){
        free(root);
        return NULL;
    }
    temp=root;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prv->next=NULL;
    free(root);
    return root;
}











int main()
{
struct node*root=NULL,*temp;
int n,j;
 while(1)
    {
        printf("\n* Enter the number of choice:\n");
        printf("1 For inserting at front: \n");
        printf("2 For inserting at rear: \n");
        printf("3 for display:\n");
        printf("4 for insert at pos:\n");
        printf("5 for count:\n");
        printf("6 for Delete at rear:\n");
        scanf("%d",&n);
        switch(n)
            {
            case 1:root=insertatfront(root);
            break;
            case 2:root=insertatrear(root);
            break;
            case 3:display(root);
            break;
            case 4:root=insertatpos(root);
            break;
            case 5:j=count(root);
            break;
            case 6:root=deleteatrear(root);
            break;
            default:
            exit(0);
            }
    }
}