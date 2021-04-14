#include "Sort.h"
#include <iomanip>
#include <unistd.h>

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
    usleep(2000);

    arr = controller.GenerateRandomNum(1000);
    SortAll(controller, arr, 1000);
    usleep(2000);

    arr = controller.GenerateRandomNum(5000);
    SortAll(controller, arr, 5000);
    usleep(2000);

    arr = controller.GenerateRandomNum(10000);
    SortAll(controller, arr, 10000);
    usleep(2000);
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

    std::cout << "\n\nInsertion Time taken for 100 numbers = " << std::fixed << insertionTime << std::setprecision(5) << "\n";
    std::cout << "Merge Time taken for 100 numbers = = " << std::fixed << mergeTime << std::setprecision(5) << "\n";
    std::cout << "Quick Time taken for 100 numbers = = " << std::fixed << quickTime << std::setprecision(5) << "\n";
}