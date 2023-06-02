#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

struct queue* create_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, int element) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void dequeue(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
    } else {
        struct node* temp = q->front;
        printf("Dequeued element is %d\n", temp->data);
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
    }
}

void display(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node* current = q->front;
        printf("Queue elements are: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, element;
    struct queue* q = create_queue();

    while (1) {
        printf("\nLinked List Queue Menu.\n1. ENQUEUE. 2. DEQUEUE. 3. DISPLAY. 4. EXIT.\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

