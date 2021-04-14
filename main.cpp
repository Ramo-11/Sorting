#include "Sort.h"
#include <iomanip>

void Menu();

int main()
{
    Sort controller;
    int sortNum = 0;
    bool keepGoing = true;

    clock_t start;
    clock_t end;
    double totalTime;

    while(keepGoing)
    {
        Menu();
        std::cin >> sortNum;
    
        if(std::cin.fail() || sortNum < 0 || sortNum > 4)
        {
            std::cout << "Invalid Input\n";
            keepGoing = false;
            continue;
        }
        
        if(sortNum == 4)
        {
            keepGoing = false;
            continue;
        }

        std::vector<int> arr = controller.GenerateRandomNum();
        std::vector<int> tempArr = arr;

        std::cout << "\nBefore Sorting";
        controller.PrintArray(tempArr);
        
        start = clock();

        if(sortNum == 1)
        {
            controller.InsertionSort(arr);

            std::cout << "\n\nAfter Sorting";
            controller.PrintArray(arr);

            int insertionCC = controller.getInsertionCC();
            std::cout << "\nCounted steps for Insertion sorting = " << insertionCC << "\n";
        }
            
        else if(sortNum == 2)
        {
            controller.MergeSort(arr, 0, arr.size() - 1);

            std::cout << "\n\nAfter Sorting";
            controller.PrintArray(arr);

            int mergeCC = controller.getMergeCC();
            std::cout << "\nCounted steps for Merge sorting = " << mergeCC << "\n";
        }
        
        else if(sortNum == 3)
        {
            controller.QuickSort(arr, 0, arr.size() - 1);  

            std::cout << "\n\nAfter Sorting";
            controller.PrintArray(arr);

            int quickCC = controller.getQuickCC();
            std::cout << "\nCounted steps for Quick sorting = " << quickCC << "\n";
        }
        
        end = clock();

        totalTime = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "\nTime taken = " << std::fixed << totalTime << std::setprecision(5) << "\n\n";
    }

    std::cout << "\n";
    return 0;
}

void Menu()
{
    std::cout << "\nPick which method you want to use to sort:\n";
    std::cout << "1- Insertion Sort\t\t2- Merge Sort\t\t3- Quick Sort\t\t4- Exit:\n";
}