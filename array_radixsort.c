#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum number in an array
int findMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

// Function to perform counting sort on the given digit
void countingSort(int array[], int n, int exp)
{
    const int radix = 10; // Base 10 for decimal numbers
    int output[n];
    int count[radix] = {0};

    // Count occurrences of each digit at the given place value
    for (int i = 0; i < n; i++)
    {
        count[(array[i] / exp) % radix]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < radix; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array using the count information
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % radix] - 1] = array[i];
        count[(array[i] / exp) % radix]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int array[], int n)
{
    // Find the maximum number to determine the number of digits
    int max = findMax(array, n);

    // Perform counting sort for every digit place value
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, n, exp);
    }
}

// Function to print an array
void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, n);

    radixSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
