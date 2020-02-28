// An array inversion is when i < j and A[i] > A[j].
// Count number of such occurances.

#include <iostream>

int merge(int array[], int begin, int mid, int end)
{
    int inversions = 0;
    
    int size1 = mid - begin + 1;
    int size2 = end - mid;
    
    int array1[size1];
    int array2[size2];
    
    for (int i = 0; i < size1; i++)
        array1[i] = array[begin + i];
    for (int i = 0; i < size2; i++)
        array2[i] = array[mid + 1 + i];
       
    int arrIndex = begin;
    int arrIndex1 = 0;
    int arrIndex2 = 0;
    
    while ((arrIndex1 < size1) && (arrIndex2 < size2))
    {
        if (array1[arrIndex1] > array2[arrIndex2])
        {
            inversions += size1 - arrIndex1;
            ++arrIndex2;
        }
        else
        {
            ++arrIndex1;    
        }
    }
    
    arrIndex1 = arrIndex2 = 0;
    
    while ((arrIndex1 < size1) && (arrIndex2 < size2))
        array[arrIndex++] = (array1[arrIndex1] < array2[arrIndex2]) ? array1[arrIndex1++] : array2[arrIndex2++];
        
    while (arrIndex1 < size1)
        array[arrIndex++] = array1[arrIndex1++];
        
    while (arrIndex2 < size2)
        array[arrIndex++] = array2[arrIndex2++];
        
    return inversions;
}

int findInversionsInArray(int array[], int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        int x = findInversionsInArray(array, begin, mid);
        int y = findInversionsInArray(array, mid + 1, end);
        
        return x + y + merge(array, begin, mid, end);
    }
    return 0;
}

int main()
{
    int array[] = {1, 20, 6, 4, 5};
    int size = sizeof(array) / sizeof(int);
    
    printf("Number of inversions = %d\n", findInversionsInArray(array, 0, size - 1));
    
    return 0;
}