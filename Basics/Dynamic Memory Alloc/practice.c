// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> 


// struct node {
//     int roll;
//     char name[MAX_NAME_LENGTH];
//     struct node* next;
// };

// struct node* head = NULL;

// void insert(int x, char y[]) { 
//     struct node* temp = (struct node*)malloc(sizeof(struct node));
//     temp->roll = x;
//     strcpy(temp->name, y); 
//     temp->next = head;
//     head = temp;
// }

// void display() {
//     printf("The name and roll are:\n");
//     struct node* temp = head;
//     while (temp != NULL) {
//         printf("Roll: %d\n", temp->roll);
//         printf("Name: %s\n", temp->name);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     printf("How many students: ");
//     int n, x;
//     char y[MAX_NAME_LENGTH]; 
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         printf("Enter roll: ");
//         scanf("%d", &x);
//         printf("Enter name: ");
//         scanf("%s", y); // Read name as string
//         insert(x, y);
//     }

//     display();

//     // Free memory (optional, but recommended)
//     struct node* current = head;
//     while (current != NULL) {
//         struct node* next = current->next;
//         free(current);
//         current = next;
//     }

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head;

void insert(int);
void insert(int x){
struct node* temp = (struct node *)malloc(sizeof(struct node));
temp->data = x;
temp->link = head;
head = temp;
}


void display(){
    printf("The list is\n");
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
   
}




int main(){
head = NULL;
int i,x,n;
printf("how many No's:\n");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\nEnter number\n");
    scanf("%d",&x);
    display();
}
return 0;
}