#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
    int start, end, num_ints;
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);
    printf("Enter the number of random integers to generate: ");
    scanf("%d", &num_ints);

    // Initialize random number generator
    srand(time(NULL));

    // Generate random integers within the specified range
    int i;
    Node* head = NULL;
    for (i = 0; i < num_ints; i++) {
        int random_num = start + rand() % (end - start + 1);
        insertNode(&head, random_num);
    }

    // Get user input for file name to save the list of random integers
    char file_name[50];
    printf("Enter the name of the file to save: ");
    scanf("%s", file_name);

    // Save the list of random integers to the specified file
    FILE* f = fopen(file_name, "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        freeList(&head);
        return 1;
    }
    Node* current = head;
    while (current != NULL) {
        fprintf(f, "%d\n", current->data);
        current = current->next;
    }
    fclose(f);

    freeList(&head);
    printf("%d random integers have been generated and saved to %s.\n", num_ints, file_name);
    return 0;
}

