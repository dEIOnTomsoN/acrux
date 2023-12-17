#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
struct Node* createNode(char data);
struct Node* createDoublyLinkedList(char* str);
void reverseDoublyLinkedList(struct Node** head);
void displayDoublyLinkedList(struct Node* head);

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from the input
    inputString[strcspn(inputString, "\n")] = '\0';

    // Create a doubly linked list from the input string
    struct Node* head = createDoublyLinkedList(inputString);

    // Display the original string
    printf("\nOriginal String: ");
    displayDoublyLinkedList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(&head);

    // Display the reversed string
    printf("\nReversed String: ");
    displayDoublyLinkedList(head);

    // Free the memory allocated for the nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to create a new node for the doubly linked list
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Function to create a doubly linked list from a string
struct Node* createDoublyLinkedList(char* str) {
    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < strlen(str); i++) {
        struct Node* newNode = createNode(str[i]);

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    return head;
}

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Update the head to point to the last node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to display a doubly linked list
void displayDoublyLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}
