#include <iostream>

void displayArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int array[], int beginIndex, int midIndex, int endIndex)
{
    int n1 = midIndex - beginIndex + 1;
    int n2 = endIndex - midIndex;

    int array1[n1];
    int array2[n2];

    for (int i = 0; i < n1; i++)
        array1[i] = array[beginIndex + i];
    for (int i = 0; i < n2; i++)
        array2[i] = array[midIndex + 1 + i];

    int arrayIndex = beginIndex;
    int arrayIndex1 = 0;
    int arrayIndex2 = 0;

    while ((arrayIndex1 < n1) && (arrayIndex2 < n2))
        array[arrayIndex++] = (array1[arrayIndex1] < array2[arrayIndex2]) ? array1[arrayIndex1++] : array2[arrayIndex2++];

    while (arrayIndex1 < n1)
        array[arrayIndex++] = array1[arrayIndex1++];

    while (arrayIndex2 < n2)
        array[arrayIndex++] = array2[arrayIndex2++];
}

void mergeSort(int array[], int beginIndex, int endIndex)
{
    if (beginIndex < endIndex)
    {
        int midIndex = (beginIndex + endIndex) / 2;
        mergeSort(array, beginIndex, midIndex);
        mergeSort(array, midIndex + 1, endIndex);
        merge(array, beginIndex, midIndex, endIndex);
    }
}

int main()
{
    int array[] = {8, 5, 7, 1, 3, 2, 6, 4};
    int n = sizeof(array) / sizeof(int);

    printf("This is merge sort\n");
    printf("Original Array: ");
    displayArray(array, n);

    mergeSort(array, 0, n - 1);

    printf("Sorted Array: ");
    displayArray(array, n);

    return 0;
}