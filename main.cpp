#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void InsertionSort(std::vector<int> &arr);
void MergeSort(std::vector<int> &arr, int begin, int end);
void Merge(std::vector<int> &arr, int begin, int end, int mid);
void Menu();

void PrintArray(std::vector<int> &arr);
std::vector<int> GenerateRandomNum();

int main()
{
    int sortNum = 0;

    std::cout << "Pick which method you want to use to sort:\n";
    std::cout << "1- Insertion Sort\t\t2- Merge Sort:\n";

    std::cin >> sortNum;

    std::vector<int> arr = GenerateRandomNum();

    std::cout << "\nBefore Sorting";
    PrintArray(arr);

    switch(sortNum)
    {
        case 1:
            InsertionSort(arr);
            break;
        
        case 2:
            MergeSort(arr, 0, arr.size() - 1);
            break;

        default:
            std::cout << "Invalid Input\n";
    }
    
    std::cout << "\n\nAfter Sorting";
    PrintArray(arr);

    std::cout << "\n";
    return 0;
}

void InsertionSort(std::vector<int> &arr)
{
    int numsBeforeKey;
    int key;

    for(int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        numsBeforeKey = i - 1;

        //swap all of the elements between key and all of the elements before it
        for(numsBeforeKey; numsBeforeKey >= 0 && arr[numsBeforeKey] > key; numsBeforeKey--)
        {
            arr[numsBeforeKey + 1] = arr[numsBeforeKey];
        }

        //This line makes sure the value that was just swapped is not lost
        arr[numsBeforeKey + 1] = key;
    }
}

void PrintArray(std::vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(i % 10 == 0)
            std::cout << "\n"; 
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

std::vector<int> GenerateRandomNum()
{
    int userChoice;
    int randomNum;
    std::vector<int> arr;

    std::cout << "Enter a number to generate random numbers:\n";
    std::cin >> randomNum;

    std::srand(randomNum);

    std::cout << "\nHow many numbers would you like to be generated?\n";
    std::cin >> userChoice;
    
    for(int i = 0; i < userChoice; i++)
    {
        randomNum = rand() % 1000;
        arr.push_back(randomNum);
    }

    return arr;
}

void MergeSort(std::vector<int> &arr, int begin, int end)
{
    if(begin < end)
    {
        int mid = (begin + end) / 2;

        MergeSort(arr, begin, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, begin, end, mid);
    }
}

void Merge(std::vector<int> &arr, int begin, int end, int mid)
{
    int i = begin;
    int k = begin; 
    int j = mid + 1; 

    std::vector<int> c;
    c.resize(arr.size());
    
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = begin; i < k; i++)
    {
        arr[i] = c[i];
    }
}