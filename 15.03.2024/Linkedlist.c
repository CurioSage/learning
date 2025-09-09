// #include <stdio.h>
// #include <stdlib.h>

// // Define the node structure
// struct Node {
//     int data;
//     char name[10];
//     struct Node* next;
// };
// typedef struct Node* node;

// // Function to create a new node
// node createNode(int value) {
//     node newNode = (node)malloc(sizeof(struct Node));
//     newNode->data = value;
//     newNode->name = value;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to add a node to the end of the linked list
// node addNode(node head, int value) {
//     node temp, p;
//     temp = createNode(value);
//     if (head == NULL) {
//         head = temp;
//     } else {
//         p = head;
//         while (p->next != NULL) {
//             p = p->next;
//         }
//         p->next = temp;
//     }
//     return head;
// }

// // Function to print the linked list
// void printList(node head) {
//     node current = head;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// void display(struct node *head)
// {
//     struct node *temp;
//     temp = root;
//     while (temp->next != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("%d\n", temp->data);
// }





// int main() {
// struct node *temp;
// int n;
// printf("enter the name of student\n");

//     return 0;
// }





#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int);
void insert(int x ){
struct node* temp = (struct node *)malloc(sizeof(struct node));
temp->data = x;
temp->next = head;
head=temp;
}

void display(){
    printf("The list is \n#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void insert(int);

void insert(int x ){
struct node* temp = (struct node *)malloc(sizeof(struct node));
temp->data = x;
temp->next = head;
head=temp;
}

void display(){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("The list is \n");
}



Struct node* head ;

main(){
head = NULL;
printf("how many numbers: %d\n");
int i,n,x;
for(i=0;i<n;i++){
    printf("Enter number\n");
    scanf("%d",&x);
    insert(x);
    display();
}

}");
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("\n");

    
}


int main(){

int i;
int n;
int x;
printf("how many numbers:\n");
scanf("%d",&n);

for(i=0;i<n;i++){
    printf("Enter number\n");
    scanf("%d",&x);
    insert(x);
    display();
}
free(x);
return 0;
}
