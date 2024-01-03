#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty queue
void initQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        fprintf(stderr, "Queue is full. Cannot enqueue.\n");
        exit(EXIT_FAILURE);
    }

    if (isEmpty(queue))
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = data;
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

    int dequeuedValue = queue->arr[queue->front];

    if (queue->front == queue->rear)
    {
        // Last element in the queue
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
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

    return queue->arr[queue->front];
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    do
    {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
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

    return 0;
}
