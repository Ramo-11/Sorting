#include "Sort.h"

Sort::Sort()
: insertionCC(0),
  mergeCC(0),
  quickCC(0)
{ }

Sort::~Sort()
{ }

std::vector<int> Sort::GenerateRandomNum()
{
    int userChoice;
    int randomNum;
    std::vector<int> arr;

    std::cout << "Enter a seed to generate random numbers:\n";
    std::cin >> randomNum;

    std::srand(randomNum);

    std::cout << "\nHow many numbers would you like to be generated?\n";
    std::cin >> userChoice;
    
    for(int i = 0; i < userChoice; i++)
    {
        randomNum = rand() % 100000;
        arr.push_back(randomNum);
    }

    return arr;
}

void Sort::InsertionSort(std::vector<int> &arr)
{
    int numsBeforeKey;
    int key;

    for(int i = 1; i < arr.size(); i++)
    {
        insertionCC++;

        key = arr.at(i);
        numsBeforeKey = i - 1;

        //swap all of the elements between key and all of the elements before it
        for(numsBeforeKey; numsBeforeKey >= 0 && arr.at(numsBeforeKey) > key; numsBeforeKey--)
        {
            insertionCC++;
            arr.at(numsBeforeKey + 1) = arr.at(numsBeforeKey);
        }

        //This line makes sure the value that was just swapped is not lost
        arr.at(numsBeforeKey + 1) = key;
    }
}

void Sort::MergeSort(std::vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        mergeCC++;

        int mid = (low + high) / 2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);

        Merge(arr, low, high, mid);
    }
}

void Sort::Merge(std::vector<int> &arr, int low, int high, int mid)
{
    int i = low;
    int k = low; 
    int j = mid + 1; 

    std::vector<int> c;
    c.resize(arr.size());
    
    while (i <= mid && j <= high)
    {
        mergeCC++;

        if (arr.at(i) < arr[j])
        {
            c.at(k) = arr.at(i);
            k++;
            i++;
        }
        else
        {
            c.at(k) = arr.at(j);
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        mergeCC++;

        c.at(k) = arr.at(i);
        k++;
        i++;
    }
    while (j <= high)
    {
        mergeCC++;

        c.at(k) = arr.at(j);
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        mergeCC++;

        arr.at(i) = c.at(i);
    }
}

void Sort::QuickSort(std::vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        quickCC++;

        int j = Partition(arr, low, high);
        QuickSort(arr, low, j-1);
        QuickSort(arr, j+1, high);
    }
}

int Sort::Partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr.at(high);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        quickCC++;
        // If current element is smaller than the pivot
        if (arr.at(j) < pivot)
        {
            i++; // increment index of smaller element
            Swap(&arr.at(i), &arr.at(j));
        }
    }
    Swap(&arr.at(i + 1), &arr.at(high));
    return (i + 1);
}

void Sort::Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Sort::PrintArray(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(i % 20 == 0)
            std::cout << "\n"; 
        std::cout << arr.at(i) << " ";
    }
    std::cout << "\n";
}

int Sort::getInsertionCC()
{
    return insertionCC;
}

int Sort::getMergeCC()
{
    return mergeCC;
}

int Sort::getQuickCC()
{
    return quickCC;
}