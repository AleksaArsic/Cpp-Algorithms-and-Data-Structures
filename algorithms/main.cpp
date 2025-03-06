#include <iostream>
#include <vector>
#include "SortingAlgorithms.hpp"

void testBubbleSort();
void testInsertionSort();
void testSelectionSort();
void testQuickSort();
void testMergeSort();
void testCountSort();
void testBucketSort();
void testRadixSort();
void testShellSort();

int main()
{
    testBubbleSort();
    testInsertionSort();
    testSelectionSort();
    testQuickSort();
    testMergeSort();
    testCountSort();
    testBucketSort();
    testRadixSort();
    testShellSort();

    return 0;
}

void testBubbleSort()
{
    std::cout << "******************************* BUBBLE SORT ******************************" << std::endl;
    std::vector<int> vectorToSort{ 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::BubbleSort bubbleSort;

    printVector(vectorToSort);
    bubbleSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testInsertionSort()
{
    std::cout << "***************************** INSERTION SORT *****************************" << std::endl;
    std::vector<int> vectorToSort{ 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::InsertionSort insertionSort;

    printVector(vectorToSort);
    insertionSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testSelectionSort()
{
    std::cout << "***************************** SELECTION SORT *****************************" << std::endl;
    std::vector<int> vectorToSort{ 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::SelectionSort selectionSort;

    printVector(vectorToSort);
    selectionSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testQuickSort()
{
    std::cout << "******************************* QUICK SORT *******************************" << std::endl;
    std::vector<int> vectorToSort{ 50, 70, 60, 90, 40, 80, 10, 20, 30, INT_MAX };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::QuickSort quickSort;

    printVector(vectorToSort);
    quickSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testMergeSort()
{
    std::cout << "******************************* MERGE SORT *******************************" << std::endl;
    std::vector<int> vectorToSort{ 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::MergeSort mergeSort;

    printVector(vectorToSort);
    mergeSort(SortingAlgorithms::MergeSort::MergeSortType::RECURSIVE_MERGE_SORT, vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testCountSort()
{
    std::cout << "******************************* COUNT SORT *******************************" << std::endl;
    std::vector<int> vectorToSort{ 6, 3, 9, 10, 15, 6, 8, 12, 3, 6 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::CountSort countSort;

    printVector(vectorToSort);
    countSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testBucketSort()
{
    std::cout << "******************************* BUCKET SORT ******************************" << std::endl;
    std::vector<int> vectorToSort{ 6, 3, 9, 10, 15, 6, 8, 12, 3, 6 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::BucketSort bucketSort;

    printVector(vectorToSort);
    bucketSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testRadixSort()
{
    std::cout << "******************************* RADIX SORT *******************************" << std::endl;
    std::vector<int> vectorToSort{ 237, 146, 259, 348, 152, 163, 235, 48, 36, 62 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::RadixSort radixSort;

    printVector(vectorToSort);
    radixSort(SortingAlgorithms::RadixSort::NumeralSystem::DECIMAL, vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}

void testShellSort()
{
    std::cout << "******************************* SHELL SORT *******************************" << std::endl;
    std::vector<int> vectorToSort{ 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 };
    SortingAlgorithms::PrintVector printVector;
    SortingAlgorithms::ShellSort shellSort;

    printVector(vectorToSort);
    shellSort(vectorToSort);
    printVector(vectorToSort);
    std::cout << "**************************************************************************" << std::endl;
}