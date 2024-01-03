#include <stdio.h>

// Function to perform Shell Sort on an array
void shellSort(int arr[], int n)
{
    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort on subarrays defined by the gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Perform Shell Sort
    shellSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
