#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        // Check if the key is present at the middle
        if (arr[mid] == key)
        {
            return mid; // Key found, return the index
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; // Search the right half
        }
        else
        {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Key not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 42, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 16;
    int result = binarySearch(arr, size, key);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", key, result);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
