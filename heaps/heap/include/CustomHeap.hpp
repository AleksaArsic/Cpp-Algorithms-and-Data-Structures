#pragma once
#include <memory>
#include <iostream>

namespace CustomHeap
{
    class Heap final
    {
        public:
            enum class HeapType
            {
                MAX_HEAP,
                MIN_HEAP
            };

            Heap() = delete;
            Heap(const HeapType& heapType, const unsigned int size);
            Heap(const HeapType& heapType, unsigned int size, std::unique_ptr<int[]>& dataArray);

            void Heapify();
            void Insert(unsigned int noOfElements);
            [[nodiscard]] int Delete();
            [[nodiscard]] unsigned int StorageSize() const;
            [[nodiscard]] unsigned int Size() const;
            void HeapSort();

            friend std::ostream& operator<<(std::ostream & os, const Heap & heap);
        private:
            HeapType type;
            unsigned int storageSize;
            unsigned int currentIdx;
            std::unique_ptr<int[]> heapArray;

            [[nodiscard]] bool compareElementsByHeapType(const int a, const int b);
    };
}