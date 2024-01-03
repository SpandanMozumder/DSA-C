#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        // Assume the current index is the minimum
        minIndex = i;

        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the element at the current index
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to display an array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    displayArray(arr, n);

    // Perform selection sort
    selectionSort(arr, n);

    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}
