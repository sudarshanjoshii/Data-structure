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

void generate_input_file(char* filename, int X) {
    FILE* file = fopen(filename, "w");
    srand(time(NULL));
    for (int i = 0; i < X; i++) {
        fprintf(file, "%d\n", rand() % 1000);
    }
    fclose(file);
}

void read_input_file(char* filename, Node** head) {
    FILE* file = fopen(filename, "r");
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        insertNode(head, value);
    }
    fclose(file);
}

void log_sorting_time(char* sorting_technique, int X, double time) {
    FILE* file = fopen("log1.txt", "a");
    fprintf(file, "Sorting technique: %s, X: %d, time: %f seconds\n", sorting_technique, X, time);
    fclose(file);
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

void selection_sort(Node* head) {
    if (head == NULL)
        return;

    Node* ptr1, * ptr2;
    int temp;

    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
}

int main() {
    int X = 10000;
    char* filename = "input.txt";
    generate_input_file(filename, X);

    Node* head = NULL;
    read_input_file(filename, &head);

    clock_t start, end;
    double time_taken;

    start = clock();
    bubble_sort(head);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        log_sorting_time("Bubble sort", X, time_taken);

    freeList(&head);

    head = NULL;
    generate_input_file(filename, X);
    read_input_file(filename, &head);

    start = clock();
    selection_sort(head);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    log_sorting_time("Selection sort", X, time_taken);

    freeList(&head);

    return 0;
}

