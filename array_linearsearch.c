#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main()
{
    int arr[] = {10, 25, 8, 15, 6, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform linear search
    int index = linearSearch(arr, size, key);

    // Check if the key was found
    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
