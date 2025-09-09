#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct queue {
    int bill[MAX];
    int f;
    int r;
} cust;

int isfull(cust *x) {
    return ((x->r + 1) % MAX == x->f);
}

int isempty(cust *x) {
    return (x->r == x->f);
}

int enqueue(cust *q, int Bill) {
    if (isfull(q)) {
        printf("The queue is full\n");
        return 0;
    } else {
        q->r = (q->r + 1) % MAX;
        q->bill[q->r] = Bill;
        return 1;
    }
}

int dequeue(cust *q) {
    if (isempty(q)) {
        printf("The queue is empty\n");
        return -1;
    } else {
        q->f = (q->f + 1) % MAX;
        return q->bill[q->f];
    }
}

void display(cust *q) {
    if (isempty(q)) {
        printf("The queue is empty\n");
    } else {
        int i = (q->f + 1) % MAX;
        while (i != (q->r + 1) % MAX) {
            printf("Customer's bill: %d\n", q->bill[i]);
            i = (i + 1) % MAX;
        }
    }
}

int main() {
    int choice, temp;
    int count = 0;
    int sum = 0;
    int Bill;

    cust *s = (cust *)malloc(sizeof(cust));
    s->f = s->r = -1;

    while (1) {
        printf("Enter the choice\n1-Enter the Bill of customer\n2-To Print the total Collection of the Day\n3-Display Number of customers with Bill exceeding 1000 Rupees\n4-Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("The Bill of customer is:\n");
                scanf("%d", &Bill);
                enqueue(s, Bill);
                break;

            case 2: {
                sum = 0;
                int i = (s->f + 1) % MAX;
                while (i != (s->r + 1) % MAX) {
                    sum += s->bill[i];
                    i = (i + 1) % MAX;
                }
                printf("The total Collection of the Day is: %d\n", sum);
                break;
            }

            case 3: {
                count = 0;
                int i = (s->f + 1) % MAX;
                while (i != (s->r + 1) % MAX) {
                    if (s->bill[i] > 1000) {
                        count++;
                    }
                    i = (i + 1) % MAX;
                }
                printf("The total Customers with bill exceeding 1000 rupees is: %d\n", count);
                break;
            }

            case 4:
                free(s);
                exit(0);

            default:
                printf("Enter the correct choice\n");
                break;
        }
    }

    return 0;
}
