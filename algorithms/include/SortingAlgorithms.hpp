#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace SortingAlgorithms
{
    // Time complexity -> O(n)
    // Space complexity -> O(1) - no additional space required
    class PrintVector final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };

    // Time complexity -> min: O(n)
    // Time complexity -> O(n^2)
    // Space complexity -> O(1) - no additional space required
    class BubbleSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };

    // Time complexity -> min: O(n)
    // Time complexity -> max: O(n^2)
    // Space complexity -> O(1) - no additional space required
    class InsertionSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };

    // Time complexity -> O(n^2)
    // Space complexity -> O(1) - no additional space required
    class SelectionSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };

    // Time complexity -> min: O(nlogn)
    // Time complexity -> max: O(n^2) -> when the array is already sorted (ascending or descending)
    // Space complexity -> O(1) - no additional space required
    class QuickSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;

        private:
            void recursiveQuickSortAlg(std::vector<int>& vec, const int low, const int high) const;
            int partition(std::vector<int>& vec, const int low, const int high) const;
    };

    // Time complexity -> O(nlogn)
    // Space complexity -> array A, additional array B and the height of the stack logn
    //                  -> O(2n + logn)
    class MergeSort final
    {
        public:
            enum class MergeSortType
            {
                ITERATIVE_MERGE_SORT,
                RECURSIVE_MERGE_SORT
            };

            void operator()(const MergeSortType& type, std::vector<int>& vec) const;

        private:
            void Merge(std::vector<int>& vec, const int low, const int mid, const int high) const;
            void Partition(std::vector<int>& vec, const int low, const int high) const;
            void iterativeMergeSort(std::vector<int>& vec) const;
            void recursiveMergeSort(std::vector<int>& vec) const;
    };

    // Time complexity -> O(n)
    // Space complexity -> O(n + m) = O(n)
    //                  -> O(n + m) implies merging, but it is not happening
    //                     we have two vectors. One is to be sorted, another one for counting.
    // Count sort needs a lot of additional space, as the size of the vector that is used for counting 
    // is equal to the maximal element in the vector that is to be sorted.
    // Good when space is not an issue, because it is fast, otherwise bad.
    class CountSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };

    // Time complexity -> O(n)
    // Space complexity -> O(n + m) = O(n)
    //                  -> O(n + m) implies merging, but it is not happening
    //                     we have two vectors. One is to be sorted, another one for buckets/bins.
    // Bucket/Bin sort needs a lot of additional space, as the size of the vector that is used 
    // for storing linked lists is equal to the maximal element in the vector that is to be sorted.
    // Good when space is not an issue, because it is fast, otherwise bad.
    class BucketSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;

        private:
            struct Node
            {
                int data;
                std::unique_ptr<Node> next;
            };

            void LLInsert(std::vector<std::unique_ptr<Node>>& buckets, const int data) const;
            int LLDelete(std::vector<std::unique_ptr<Node>>& buckets, const int data) const;
    };

    // Time complexity -> O(d*n) -> d - number of buckets that is determined by the numeral system
    //                           -> d - constant
    //                 -> O(n)
    // Space complexity -> O(n)
    // Similar to Bucket and Count sort, but needs less space due to the buckets being size of 
    // numeral system in which numbers are represented.
    // Works only for the decimal system. Can be easly addapted for other numeral systems
    class RadixSort final
    {
        public:
            enum class NumeralSystem
            {
                BINARY,
                OCTAL,
                DECIMAL,
                HEXADECIMAL
            };

            void operator()(const RadixSort::NumeralSystem numeralSystem, std::vector<int>& vec) const;

        private:
            struct Node
            {
                int data;
                std::shared_ptr<Node> next;
            };

            void LLInsert(std::vector<std::shared_ptr<Node>>& buckets, const int bucketIdx, const int data) const;
            int LLDelete(std::vector<std::shared_ptr<Node>>& buckets) const;
    };

    // Time complexity -> O(nlogn)
    // Space complexity -> O(1) -> no additional space required
    class ShellSort final
    {
        public:
            void operator()(std::vector<int>& vec) const;
    };
}