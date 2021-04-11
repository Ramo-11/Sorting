#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Sort
{
    public:
        Sort();
        ~Sort();
        
        void InsertionSort(std::vector<int> &arr);
        void MergeSort(std::vector<int> &arr, int low, int high);
        void Merge(std::vector<int> &arr, int low, int high, int mid);
        void QuickSort(std::vector<int> &arr, int low, int high);
        int Partition(std::vector<int> &arr, int low, int high);

        std::vector<int> GenerateRandomNum();
        void Swap(int*, int*);
        void PrintArray(std::vector<int> &arr);
};
#endif