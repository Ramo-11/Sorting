#include "Sort.h"

void Menu();

int main()
{
    Sort controller;
    int sortNum = 0;
    bool keepGoing = true;

    std::vector<int> arr = controller.GenerateRandomNum();
    std::vector<int> tempArr = arr;

    while(keepGoing)
    {
        Menu();
        std::cin >> sortNum;
    
        std::cout << "\nBefore Sorting";
        controller.PrintArray(tempArr);
        
        if(sortNum == 1)
            controller.InsertionSort(arr);
            
        else if(sortNum == 2)
            controller.MergeSort(arr, 0, arr.size() - 1);
        
        else if(sortNum == 3)
            controller.QuickSort(arr, 0, arr.size() - 1);  
            
        else if(sortNum == 4)
            keepGoing = false;
            
        else 
        {
            std::cout << "Invalid Input\n";
            keepGoing = false;
        }
        
        std::cout << "\n\nAfter Sorting";
        controller.PrintArray(arr);
    }

    std::cout << "\n";
    return 0;
}

void Menu()
{
    std::cout << "\nPick which method you want to use to sort:\n";
    std::cout << "1- Insertion Sort\t\t2- Merge Sort\t\t3- Quick Sort\t\t4- Exit:\n";
}