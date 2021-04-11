#include <iostream>
#include <Vector>
#include <cstdlib>
#include <ctime>

void InsertionSort(std::vector<int> *arr);
void MergeSort(std::vector<int> *arr);

void PrintArray(std::vector<int> *arr);
std::vector<int> GenerateRandomNum();

int main()
{
    std::vector<int> arr = GenerateRandomNum();

    std::cout << "\nBefore Sorting";
    PrintArray(&arr);

    InsertionSort(&arr);

    std::cout << "\n\nAfter Sorting";
    PrintArray(&arr);

    std::cout << "\n";
    return 0;
}

void InsertionSort(std::vector<int> *arr)
{
    int numsBeforeKey;
    int key;

    for(int i = 1; i < arr->size(); i++)
    {
        key = (*arr)[i];
        numsBeforeKey = i - 1;

        //swap all of the elements between key and all of the elements before it
        for(numsBeforeKey; numsBeforeKey >= 0 && (*arr)[numsBeforeKey] > key; numsBeforeKey--)
        {
            (*arr)[numsBeforeKey + 1] = (*arr)[numsBeforeKey];
        }

        //This line makes sure the value that was just swapped is not lost
        (*arr)[numsBeforeKey + 1] = key;
    }
}

void PrintArray(std::vector<int> *arr)
{
    for(int i = 0; i < arr->size(); i++)
    {
        if(i % 10 == 0)
            std::cout << "\n"; 
        std::cout << (*arr)[i] << " ";
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