#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[100];
    int id;
    int salary;
    struct node *next;
    struct node *prev;
} *node;

node create_node() {
    node newnode;
    newnode = (node)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the name of the employee:\n");
    scanf("%s", newnode->name);
    printf("Enter the ID of the employee:\n");
    scanf("%d", &newnode->id);
    printf("Enter the salary of the employee:\n");
    scanf("%d", &newnode->salary);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

node insert_rear(node root) {
    node temp, newnode;
    newnode = create_node();
    if (root == NULL) {
        return newnode;
    }
    temp = root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return root;
}

node insert_front(node root) {
    node temp, newnode;
    newnode = create_node();
    if (root == NULL) {
        return newnode;
    }
    temp = root;
    newnode->next = temp;
    temp->prev = newnode;
    root = newnode;
    return root;
}

void display(node root) {
    node temp;
    temp = root;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL) {
        printf("Name: %s\n", temp->name);
        printf("ID: %d\n", temp->id);
        printf("Salary: %d\n", temp->salary);
        temp = temp->next;
    }
    // printf("Name: %s\n", temp->name);
    // printf("ID: %d\n", temp->id);
    // printf("Salary: %d\n", temp->salary);
}

int main() {
    node root = NULL;
    int choice;
    for (;;) {
        printf("1 - Insert Rear\n2 - Display\n3 - Insert Front\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                root = insert_rear(root);
                break;
            case 2:
                printf("Displaying List\n");
                display(root);
                break;
            case 3:
                root = insert_front(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
