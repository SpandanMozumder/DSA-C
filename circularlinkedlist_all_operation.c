#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the circular linked list
struct Node *addToBeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself for the first node
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
    return newNode;
}

// Function to add a node at the end of the circular linked list
struct Node *addToEnd(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself for the first node
        return newNode;
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
        return head;
    }
}

// Function to add a node at a specific position in the circular linked list
struct Node *addToPosition(struct Node *head, int value, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return head;
    }

    if (position == 1)
    {
        return addToBeginning(head, value);
    }
    else
    {
        struct Node *newNode = createNode(value);
        struct Node *temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; ++i)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Position out of bounds\n");
            return head;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
}

// Function to delete a node from the beginning of the circular linked list
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    if (temp->next == head)
    {
        // Only one node in the list
        free(temp);
        return NULL;
    }
    else
    {
        head = temp->next;
        last->next = head;
        free(temp);
        return head;
    }
}

// Function to delete a node from the end of the circular linked list
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = head;
    struct Node *last = head;
    struct Node *secondLast = NULL;

    while (last->next != head)
    {
        secondLast = last;
        last = last->next;
    }

    if (temp->next == head)
    {
        // Only one node in the list
        free(temp);
        return NULL;
    }
    else
    {
        secondLast->next = head;
        free(last);
        return head;
    }
}

// Function to delete a node from a specific position in the circular linked list
struct Node *deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL || position <= 0)
    {
        printf("List is empty or invalid position\n");
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (position == 1)
    {
        // Delete the first node
        return deleteFromBeginning(head);
    }

    for (int i = 1; i < position && temp->next != head; ++i)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        // Position out of bounds
        printf("Position out of bounds\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to reverse the circular linked list
struct Node *reverseList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *current = head;
    struct Node *prev = NULL, *next = NULL;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    return prev;
}

// Function to print the circular linked list
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Adding nodes to the circular linked list
    head = addToEnd(head, 1);
    head = addToEnd(head, 2);
    head = addToEnd(head, 3);

    printf("Original List: ");
    printList(head);

    // Adding a node at the beginning
    head = addToBeginning(head, 0);
    printf("After adding at the beginning: ");
    printList(head);

    // Adding a node at a position
    head = addToPosition(head, 4, 3);
    printf("After adding at position 3: ");
    printList(head);

    // Deleting a node from the end
    head = deleteFromEnd(head);
    printf("After deleting from end: ");
    printList(head);

    // Deleting a node from a position
    head = deleteFromPosition(head, 2);
    printf("After deleting from position 2: ");
    printList(head);

    // Reversing the list
    head = reverseList(head);
    printf("After reversing the list: ");
    printList(head);

    return 0;
}
