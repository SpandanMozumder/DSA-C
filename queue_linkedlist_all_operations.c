#include <stdio.h>
#include <stdlib.h>

// Node structure for a queue
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to initialize an empty queue
void initQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into the queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = temp->next;
    free(temp);
    // If the queue becomes empty after dequeue, update rear to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    printf("Dequeued %d from the queue\n", dequeuedValue);
    return dequeuedValue;
}

// Function to peek at the front element of the queue
int peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty. Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *current = queue->front;
    printf("Queue: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void freeQueue(struct Queue *queue)
{
    while (queue->front != NULL)
    {
        struct Node *temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
}

int main()
{
    struct Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    displayQueue(&myQueue);

    printf("Front element: %d\n", peek(&myQueue));

    dequeue(&myQueue);

    displayQueue(&myQueue);

    freeQueue(&myQueue);

    return 0;
}
