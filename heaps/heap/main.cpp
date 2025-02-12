#include <iostream>
#include <memory>
#include "CustomHeap.hpp"

void printUniquePtrArray(const std::unique_ptr<int[]>& array, unsigned int size)
{
    std::cout << "UniquePtr: ";

    if (array.get() != nullptr)
    {
        for (unsigned int i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "UniquePtr is empty." << std::endl;
    }
    
}

int main()
{
    std::cout << "******************************************* EMPTY HEAP *******************************************" << std::endl;
    CustomHeap::Heap heapTest(CustomHeap::Heap::HeapType::MIN_HEAP, 10U);
    std::cout << heapTest << std::endl;
    std::cout << "Heap storage size: " << heapTest.StorageSize() << std::endl;
    std::cout << "Heap size: " << heapTest.Size() << std::endl;
    std::cout << "**************************************************************************************************" << std::endl;

    std::cout << "******************************************* HEAP *******************************************" << std::endl;
    constexpr unsigned int dataSize = 12U;
    std::unique_ptr<int[]> data(new int[] {6, 23, 3, 54, 11, -2, 17, 8, 91, -10, -23, 550});
    printUniquePtrArray(data, dataSize);

    CustomHeap::Heap heap(CustomHeap::Heap::HeapType::MIN_HEAP, dataSize, data);

    std::cout << heap << std::endl;
    std::cout << "Heap storage size: " << heap.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap.Size() << std::endl;
    printUniquePtrArray(data, dataSize);

    //heap.Insert(heap.StorageSize());
    heap.Insert(6U);
    heap.Insert(6U);
    std::cout << heap << std::endl;
    std::cout << "Heap storage size: " << heap.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap.Size() << std::endl;

    std::cout << "Delete from heap: " << heap.Delete() << std::endl;
    std::cout << heap << std::endl;
    std::cout << "Heap storage size: " << heap.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap.Size() << std::endl;

    heap.HeapSort();
    std::cout << heap << std::endl;
    std::cout << "Heap storage size: " << heap.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap.Size() << std::endl;
    std::cout << "********************************************************************************************" << std::endl;

    std::cout << "******************************************* HEAP *******************************************" << std::endl;
    constexpr unsigned int dataSize2 = 12U;
    std::unique_ptr<int[]> data2(new int[] {6, 23, 3, 54, 11, -2, 17, 8, 91, -10, -23, 550});
    printUniquePtrArray(data2, dataSize2);

    CustomHeap::Heap heap2(CustomHeap::Heap::HeapType::MIN_HEAP, dataSize2, data2);

    std::cout << heap2 << std::endl;
    std::cout << "Heap storage size: " << heap2.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap2.Size() << std::endl;
    printUniquePtrArray(data2, dataSize2);

    heap2.Heapify();
    std::cout << heap2 << std::endl;
    std::cout << "Heap storage size: " << heap2.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap2.Size() << std::endl;

    heap2.HeapSort();
    std::cout << heap2 << std::endl;
    std::cout << "Heap storage size: " << heap2.StorageSize() << std::endl;
    std::cout << "Heap size: " << heap2.Size() << std::endl;

    std::cout << "********************************************************************************************" << std::endl;

    return 0;
}