#include <iostream>

void InsertionSort(int *array, int n);
void PrintArray(int *array, int n);

int main()
{
    int arr[5] = { 12, 11, 13, 5, 6 };

    PrintArray(arr, 5);

    InsertionSort(arr, 5);

    PrintArray(arr, 5);

    std::cout << "\n";
    return 0;
}

void InsertionSort(int *array, int n)
{
    int numsBeforeKey;
    int key;

    for(int i = 1; i < n; i++)
    {
        key = array[i];
        numsBeforeKey = i - 1;

        //swap all of the elements between key and all of the elements before it
        for(numsBeforeKey; numsBeforeKey >= 0 && array[numsBeforeKey] > key; numsBeforeKey--)
        {
            array[numsBeforeKey + 1] = array[numsBeforeKey];
        }

        //This line makes sure the value that was just swapped is not lost
        array[numsBeforeKey + 1] = key;
    }
}

void PrintArray(int *array, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}