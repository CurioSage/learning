#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gal {
    int img_id;
    int size;
    struct gal* next;
    struct gal* prv;
} gal;

struct gal* createnode() {
    struct gal* newnode;
    newnode = (struct gal*)malloc(sizeof(struct gal));
    if (newnode == NULL) {
        printf("Node not created\n");
        exit(0);
    }
    
    printf("Enter the img_id: ");
    scanf("%d", &newnode->img_id);
    printf("Enter the size of image: ");
    scanf("%d", &newnode->size);
    newnode->next = NULL;
    newnode->prv = NULL;
    return newnode;
}


struct gal* count(struct gal* head) {
    int count = 0;
    struct gal* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("The total images are: %d\n", count);
}

struct gal* insert_rear(struct gal* head) {
    struct gal* temp, *newnode;
    newnode = createnode();
    if (head == NULL) {
        return newnode;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prv = temp;
    return head;
}

struct gal* delete_front(struct gal* head) {
    struct gal* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prv = NULL;

    }
    free(temp);
    return head;
}

struct gal* display(struct gal* head) {
    struct gal* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        int flag = 0;
        while (temp != NULL) {
            if (temp->size > 4) {
                printf("\nThe image with size greater than 4MB is: %d\n", temp->img_id);
                flag = 1;
            }
            temp = temp->next;
        }
        if (!flag) {
            printf("No images greater than 4MB\n");
        }
    }
    printf("\n");
}

int main() {
    struct gal* head = NULL;
    int choice;
    while (1) {
        printf("\n1 - Copy Image\n2 - Count the images\n3 - Display the images greater than 4MB\n4 - Delete the image\n5 - Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = insert_rear(head);
                break;
            case 2:
                count(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Front element deleted\n");
                head = delete_front(head);
                break;
            case 5:
                printf("Program exited\n");
                exit(0);
        }
    }
    return 0;
}

