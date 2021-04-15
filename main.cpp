#include "Sort.h"
#include <iomanip>

void Menu();
void SortAll(Sort controller, std::vector<int> arr, int number);

clock_t start;
clock_t end;
double insertionTime;
double mergeTime;
double quickTime;

int main()
{
    Sort controller;
    std::vector<int> arr;

    arr = controller.GenerateRandomNum(100);

    std::cout <<"Before sorting 100 elements:\n";
    controller.PrintArray(arr);
    controller.InsertionSort(arr);

    std::cout << "\nAfter sorting 100 elements:\n";
    controller.PrintArray(arr);

    arr = controller.GenerateRandomNum(1000);

    std::cout <<"\n\n\nBefore sorting 1000 elements:\n";
    controller.PrintArray(arr);
    controller.InsertionSort(arr);

    std::cout << "\nAfter sorting 1000 elements:\n";
    controller.PrintArray(arr);

    arr = controller.GenerateRandomNum(100);
    SortAll(controller, arr, 100);

    arr = controller.GenerateRandomNum(1000);
    SortAll(controller, arr, 1000);

    arr = controller.GenerateRandomNum(5000);
    SortAll(controller, arr, 5000);

    arr = controller.GenerateRandomNum(10000);
    SortAll(controller, arr, 10000);
}

void SortAll(Sort controller, std::vector<int> arr, int number)
{
    start = clock();
    controller.InsertionSort(arr);
    end = clock();

    insertionTime = double(end - start) / double(CLOCKS_PER_SEC);

    start = clock();
    controller.MergeSort(arr, 0, arr.size() - 1);
    end = clock();

    mergeTime = double(end - start) / double(CLOCKS_PER_SEC);
    

    start = clock();
    controller.QuickSort(arr, 0, arr.size() - 1);
    end = clock();

    quickTime = double(end - start) / double(CLOCKS_PER_SEC);

    std::cout << "\n\nInsertion Time taken for " << number << " numbers = " << std::fixed << insertionTime << std::setprecision(5) << " seconds\n";
    std::cout << "Insertion steps for " << number << " numbers = " << controller.getInsertionCC() << "\n\n\n";
    std::cout << "Merge Time taken for " << number << " numbers  = " << std::fixed << mergeTime << std::setprecision(5) << " seconds\n";
    std::cout << "Merge steps for " << number << " numbers = " << controller.getMergeCC() << "\n\n\n";
    std::cout << "Quick Time taken for " << number << " numbers  = " << std::fixed << quickTime << std::setprecision(5) << " seconds\n";
    std::cout << "Quick steps for " << number << " numbers = " << controller.getQuickCC() << "\n";
}