#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct node
{
    char Sname[100];
    char Singername[100];
    char S_id[100];
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
     printf("Enter song name: ");
    scanf("%s", newnode->Sname);
    printf("Enter Singer Name : ");
    scanf("%d", newnode->Singername);
    printf("Enter song id: ");
    scanf("%d", newnode->S_id);
    newnode->next=NULL;
    newnode->prv=NULL;

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


int display(struct node*root)
{
struct node*temp;
temp=root;
while(temp->next!=NULL)
{

    printf("Song List is:\n");
    printf("Song name: %s Singer Name: %s Song id:%s\n",temp->Sname,temp->Singernamename,temp->S_id);
    temp=temp->next;

}
while(temp->prv!=NULL)
{

    printf("Song List is:\n");
    printf("Song name: %s Singer Name: %s Song id:%s\n",temp->Sname,temp->Singernamename,temp->S_id);
    temp=temp->prv;
}
return 0 ;
}


struct node* search_name(node *root)
{
    struct node *temp;
    char name1[20];
    int data1,flag=0;
    if(head==NULL)
    {
        printf("List is empty");
        exit(0);
    }
    printf("Enter the name for searching");
    scanf("%s",name1);
    temp=head;
    while(temp->next!=NULL)
    {
         if(strcmp(temp->Sname,name1)==0)
         {
             printf("\n Data Found \n");
             printf("Song name: %s\n",temp->Sname);
             printf("Singer Name: %s\n",temp->Singernamename);
             printf("Song id: %s\n",temp->S_id);
             flag=1;
             break;
         }
         temp=temp->next;
    }
    if(flag==0)
    {
        printf("Data not found!");
    }

    return head;
}




struct node* delete_pos(node *root)
{
    node *temp,*prev1=NULL;
    int pos,count;
    if(root==NULL)
    {
        printf("List is Empty");
        exit(0);
    }
    printf("Enter the position");
    scanf("%d",&pos);
    count=countnode(root);
    if(pos<1 ||pos >count)
    {
        printf("Invalid Position");
    }
    else if(pos==1)
    {
        root=delete_front(root);
    }
    else if(pos==count)
    {
        root=delete_rear(root);
    }
    else
    {
        temp=root;
        for(int i=1;i<pos;i++)
        {
            prev1=temp;
            temp=temp->next;
        }
      node *temp1;
      temp1=temp->next;
      prev1->next=temp1;
      temp1->prev=prev1;
        free(temp);
    }
    return root;
}

int main()
{
    node *root=NULL;
    int choice,count;
    while(1)
    {
        printf("\nEnter the choice.\n1 For inserting at rare position.\n2 For inserting at front.\n3 For display elements.\n4 To count number of nodes.\n5 To delete at the rear.\n6 To delete at the front.\n7 To insert at specific position.\n8 To delete at specific position.\n9 To search an element.\n 10 for searching and delete\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: root=insert_rear(root);
                    break;
            case 2: root=insert_front(root);
                    break;
            case 3: display(root);
                    break;
            case 4: count=countnode(root);
                    printf("\nThere are %d no of nodes in the list",count);
                    break;
            case 5: root=delete_rear(root);
                    break;
            case 6: root=delete_front(root);
                    break;
            case 7: root=insert_pos(root);
                    break;
            case 8: root=delete_pos(root);
                    break;
            case 9: search(root);
                    break;
            case 10:root=searchdelete(root);
                    break;

            default:exit(0);
        }
    }
    apar *temp=root;
    apar *next;
    while(temp->next!=root)
    {
        next=temp->next;
        free(temp);
        next=temp;
    }
    return 0;
}





