
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patientdetails {
    char name[20];
    int age;
    char id[20];
    int contact;
    char address[100];
    struct patientdetails *next; 
} *node; 


node insert_end(node head);
int display(node head);








int main() {
    node head = NULL;
    for (int i = 0; i < 2; i++) {
        head = insert_end(head); 
    }
    display(head);
    char search[20];
    printf("\nEnter the ID to search for patient information: ");
    scanf("%s", search);
    search_display(head, search);
    

    return 0;
}









node insert_end(node head) {
    node new_node = (node)malloc(sizeof(struct patientdetails));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1); 
    }

    printf("Enter the name of the patient: ");
    scanf("%s", new_node->name);
    printf("Enter the age of the patient: ");
    scanf("%d", &new_node->age);
    printf("Enter the id of the patient: ");
    scanf("%s", new_node->id);
    printf("Enter the contact of the patient: ");
    scanf("%d", &new_node->contact);
    printf("Enter the address of the patient: ");
    getchar(); 
    fgets(new_node->address, sizeof(new_node->address), stdin); 
    new_node->next = NULL;

    if (head == NULL) {
        return new_node; 
    }

    node temp1 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = new_node;
    return head;
}

int display(node head) {
    node temp = head;
    while (temp != NULL) {
        printf("Name: %s\nAge: %d\nID: %s\nContact: %d\nAddress: %s\n",
               temp->name, temp->age, temp->id, temp->contact, temp->address);
        temp = temp->next;
    }
    return 0;
}

int search_display(node head, char search[20]) {
    node new_node = head;
    while (new_node != NULL) {
        if (strcmp(new_node->id, search) == 0) {
            printf("\nName: %s", new_node->name);
            printf("\nAge: %d", new_node->age);
            printf("\nID: %ls", new_node->id);
            printf("\ncontact: %d", new_node->contact);
            printf("\naddress: %s", new_node->address);
            return 0; 
        }
        new_node = new_node->next;
    }
    printf("\nPatient with ID '%s' not found!\n", search);
    return 0;
}





