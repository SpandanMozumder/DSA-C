#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and display the linked list
void traverseLinkedList(Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to insert a node at a given position in the linked list
Node *insertAtPosition(Node *head, int data, int position)
{
    Node *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    int i = 0;
    while (i < position - 1 && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
    {
        printf("Invalid position for insertion\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the linked list
Node *deleteFromBeginning(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from beginning.\n");
        return NULL;
    }

    Node *newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete a node from the end of the linked list
Node *deleteFromEnd(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from end.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node from a given position in the linked list
Node *deleteFromPosition(Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from position.\n");
        return NULL;
    }

    if (position == 0)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }

    Node *current = head;
    int i = 0;
    while (i < position - 1 && current != NULL)
    {
        current = current->next;
        i++;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position for deletion\n");
        return head;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to reverse the linked list
Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to free the memory allocated for the linked list
void freeLinkedList(Node *head)
{
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Node *head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 1);
    traverseLinkedList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 9);
    traverseLinkedList(head);

    // Insert node at a given position
    head = insertAtPosition(head, 6, 2);
    traverseLinkedList(head);

    // Delete nodes
    head = deleteFromBeginning(head);
    traverseLinkedList(head);

    head = deleteFromEnd(head);
    traverseLinkedList(head);

    head = deleteFromPosition(head, 2);
    traverseLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);
    traverseLinkedList(head);

    // Free memory
    freeLinkedList(head);

    return 0;
}
