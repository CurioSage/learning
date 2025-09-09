#include <stdio.h>
#include <stdlib.h>

struct node {
    char text[1000];
    char date[10];
    int time;
    struct node* next;
    struct node* prv;
}node;

struct node* createnode()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Node not created\n");
        exit(0);
    }
    
    printf("Enter the Text: \n");
    scanf("%s", newnode->text);
    printf("Enter the Todays date: \n");
    scanf("%s", newnode->date);
    printf("Enter the time: \n");
    scanf("%d", &newnode->time);
    newnode->next = NULL;
    newnode->prv = NULL;
    return newnode;
}

struct node* insert_rear(struct node* root)
{
    struct node* temp, * newnode;
    newnode = createnode();
    if(root == NULL)
    {
        return newnode;
    }
    temp = root;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prv = temp;
    return root;
}


struct node* delete_rear(struct node* root)
{
    struct node* temp;
    if(root == NULL)
    {
        printf("Text is empty\n");
        return NULL;
    }
    temp = root;
    if(temp->next == NULL)
    {
        printf("Deleted Tab details: %s %s %d\n", temp->text, temp->date, temp->time);
        free(temp);
        return NULL;
    }
    
}


void display(struct node* root)
{
    struct node* temp;
    temp = root;
    if(root == NULL)
    {
        printf("Text is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("The text is: %s\nThe Modified date is: %s\nThe modified Time is: %d\n", temp->text, temp->date, temp->time);
            temp = temp->next;
        }
        
    }
    printf("\n");
}


int main()
{
    struct node* root = NULL;
    int choice;
    for(;;)
    {
        
        printf("\n1 - Insert Rear\n2 - Display\n3 - Delete rear\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                root = insert_rear(root);
                break;
            case 2:
                printf("Display List Inserted\n");
                display(root);
                break;
            case 3:
                printf("Rear element delete\n");
                root = delete_rear(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}


