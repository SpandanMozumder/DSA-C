#include <stdio.h>

// Maximum size of the array
#define MAX_SIZE 100

// Function to display the elements of the array
void displayArray(int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position in the array
void insertElement(int arr[], int *size, int position, int value)
{
    if (*size >= MAX_SIZE)
    {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    // Shift elements to make space for the new element
    for (int i = *size; i > position; --i)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position] = value;

    // Increase the size of the array
    (*size)++;
}

// Function to delete an element at a specific position in the array
void deleteElement(int arr[], int *size, int position)
{
    if (position < 0 || position >= *size)
    {
        printf("Invalid position. Cannot delete element.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = position; i < *size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0;

    // Insert elements into the array
    insertElement(arr, &size, 0, 5);
    insertElement(arr, &size, 1, 10);
    insertElement(arr, &size, 2, 15);

    // Display the array after insertion
    displayArray(arr, size);

    // Insert an element at position 1
    insertElement(arr, &size, 1, 8);

    // Display the array after the second insertion
    displayArray(arr, size);

    // Delete an element at position 2
    deleteElement(arr, &size, 2);

    // Display the array after deletion
    displayArray(arr, size);

    return 0;
}
