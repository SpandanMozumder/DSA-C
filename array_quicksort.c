#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            // Swap arr[i+1] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot in its correct position)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the pivot index
}

// Function to implement the QuickSort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Find the pivot element such that elements smaller than the pivot
        // are on the left, and elements greater than the pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays on the left and right of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 7, 1, 6, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
