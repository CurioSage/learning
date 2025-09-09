#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    int rollno;
    float cgpa;
    struct node *next;
} link;

link* createnode() {
    link *newnode = (link *)malloc(sizeof(link));
    if (newnode == NULL) {
        printf("Node not created");
        exit(1);  // Exit with a non-zero value to indicate an error
    }
    printf("Enter the student Name: ");
    scanf("%19s", newnode->name);  // Use field width to prevent buffer overflow
    printf("Enter the student rollno: ");
    scanf("%d", &newnode->rollno);
    printf("Enter the scored CGPA: ");
    scanf("%f", &newnode->cgpa);
    newnode->next = NULL;
    return newnode;
}

// ... (the rest of the functions remain the same) ...

int main() {
    link *head = NULL;
    int choice, count;
    while (1) {
        printf("\nEnter the choice.\n1 For inserting at rear position.\n2 For inserting at front.");
        printf("\n3 For display elements.\n4 To count number of nodes.");
        printf("\n5 To delete at the rear.\n6 To delete at the front.");
        printf("\n7 To insert at specific position.\n8 To delete at specific position.");
        printf("\n9 To search an element.\n10 for searching by name\n");
        scanf("%d", &choice);
        switch (choice) {
            // ... (cases remain the same) ...
            default:
                // Free the linked list memory before exiting
                link *temp = head;
                link *next;
                while (temp != NULL) {
                    next = temp->next;
                    free(temp);
                    temp = next;
                }
                exit(0);
        }
    }
    return 0;
}