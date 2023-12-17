#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeQueue(struct Queue* queue);
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
void displayQueue(struct Queue* queue);

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert element to the queue\n");
        printf("2. Delete element from the queue\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                if (queue.front == NULL)
                    printf("Queue is empty. Cannot delete.\n");
                else {
                    value = dequeue(&queue);
                    printf("Deleted element: %d\n", value);
                }
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error. Unable to enqueue.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If queue is empty, set both front and rear to the new node
        queue->front = queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element %d enqueued to the queue.\n", value);
}

int dequeue(struct Queue* queue) {
    int value;
    struct Node* temp;

    // Retrieve the value from the front of the queue
    value = queue->front->data;

    // Move front to the next node
    temp = queue->front;
    queue->front = queue->front->next;

    // If front becomes NULL, set rear to NULL as well
    if (queue->front == NULL)
        queue->rear = NULL;

    // Free the memory of the dequeued node
    free(temp);

    return value;
}

void displayQueue(struct Queue* queue) {
    struct Node* current = queue->front;

    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
