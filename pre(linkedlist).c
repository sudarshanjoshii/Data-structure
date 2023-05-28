#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void bubble_sort(Node* head) {
    if (head == NULL)
        return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void read_input_file(char* filename, Node** head, int X) {
    FILE* file = fopen(filename, "r");
    int value;
    int count = 0;
    while (fscanf(file, "%d", &value) != EOF && count < X) {
        insertNode(head, value);
        count++;
    }
    fclose(file);
}

void write_output_file(char* filename, Node* head) {
    FILE* file = fopen(filename, "w");
    Node* current = head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }
    fclose(file);
}

int main() {
    int X = 100;
    char* inputFilename = "Input.txt";
    char* outputFilename = "out1.txt";

    Node* head = NULL;
    read_input_file(inputFilename, &head, X);

    bubble_sort(head);

    write_output_file(outputFilename, head);

    freeList(&head);

    return 0;
}
