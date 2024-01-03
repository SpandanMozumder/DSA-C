#include <stdio.h>
#include <stdlib.h>

// Circular Queue structure
struct CircularQueue
{
    int *array;
    int front;
    int rear;
    int size;
};

// Function to initialize an empty circular queue
void initCircularQueue(struct CircularQueue *queue, int size)
{
    queue->array = (int *)malloc(size * sizeof(int));
    if (queue->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue)
{
    return ((queue->rear + 1) % queue->size == queue->front);
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue *queue, int data)
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
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = data;
    printf("Enqueued %d into the circular queue\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }
    int dequeuedValue = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        // Last element is dequeued, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }
    printf("Dequeued %d from the circular queue\n", dequeuedValue);
    return dequeuedValue;
}

// Function to peek at the front element of the circular queue
int peek(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Queue is empty. Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return queue->array[queue->front];
}

// Function to display the elements of the circular queue
void displayCircularQueue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Circular Queue: ");
    do
    {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->size;
    } while (i != (queue->rear + 1) % queue->size);
    printf("\n");
}

// Function to free the memory allocated for the circular queue
void freeCircularQueue(struct CircularQueue *queue)
{
    free(queue->array);
}

int main()
{
    struct CircularQueue myQueue;
    int size = 5; // Set the size of the circular queue

    initCircularQueue(&myQueue, size);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    displayCircularQueue(&myQueue);

    printf("Front element: %d\n", peek(&myQueue));

    dequeue(&myQueue);

    displayCircularQueue(&myQueue);

    freeCircularQueue(&myQueue);

    return 0;
}
