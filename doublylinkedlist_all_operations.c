#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and display the doubly linked list
void displayList(struct Node *head)
{
    printf("Doubly Linked List: ");
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a given position in the list
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    struct Node *current = head;
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
    newNode->prev = current;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the list
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from the beginning\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end of the list
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from the end\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node from a given position in the list
struct Node *deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from the given position\n");
        return head;
    }
    if (position == 0)
    {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    struct Node *current = head;
    int i = 0;
    while (i < position && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        printf("Invalid position for deletion\n");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

// Function to reverse the doubly linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *current = head;
    struct Node *temp = NULL;

    while (current != NULL)
    {
        // Swap next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Set the head to the last node (original tail)
    if (temp != NULL)
    {
        head = temp->prev;
    }

    return head;
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    // Display the list after insertion at the beginning
    displayList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    // Display the list after insertion at the end
    displayList(head);

    // Insert node at a given position
    head = insertAtPosition(head, 35, 2);

    // Display the list after insertion at a given position
    displayList(head);

    // Delete node from the beginning
    head = deleteFromBeginning(head);

    // Display the list after deletion from the beginning
    displayList(head);

    // Delete node from the end
    head = deleteFromEnd(head);

    // Display the list after deletion from the end
    displayList(head);

    // Delete node from a given position
    head = deleteFromPosition(head, 1);

    // Display the list after deletion from a given position
    displayList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the reversed list
    displayList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}
