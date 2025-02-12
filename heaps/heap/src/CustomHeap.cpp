#include "CustomHeap.hpp"

namespace CustomHeap
{
    // Time complexity -> o(1)
    // Space complexity-> o(1)
    Heap::Heap(const HeapType& heapType, const unsigned int size) : currentIdx(0U)
    {
        type = heapType;
        storageSize = size;
        heapArray = std::make_unique<int[]>(size);
    }

    // Time complexity -> o(1)
    // Space complexity-> o(1)
    Heap::Heap(const HeapType& heapType, unsigned int size, std::unique_ptr<int[]>& dataArray) : currentIdx(0U)
    {
        type = heapType;
        storageSize = size;
        heapArray = std::move(dataArray);
    }

    // Time complexity -> o(n) - we process only n nodes (leaf do not need to be processed)
    // Space complexity -> o(1)
    void Heap::Heapify()
    {
        currentIdx = storageSize - 1U;

        for (int i = storageSize / 2L - 1L; i >= 0L; --i)
        {
            int k = (i * 2L) + 1L;

            while (k < currentIdx)
            {
                if (!compareElementsByHeapType(heapArray[k], heapArray[k + 1L]))
                {
                    k = k + 1L;
                }

                if (!compareElementsByHeapType(heapArray[i], heapArray[k]))
                {
                    std::swap(heapArray[i], heapArray[k]);
                    i = k;
                    k = 2L * i + 1L;
                }
                else
                {
                    break;
                }
            }
        }
    }

    // Time complexity -> for n elements add new element
    //                 -> when element is added we need to see if he is greater than the parent
    //                 -> if he is greater we need to swap them
    //                 -> do this at most for the height of the whole tree - logn times
    //                 -> o(n * logn)
    // Space complexity -> o(1)
    void Heap::Insert(unsigned int noOfElements)
    {

        if (noOfElements <= (storageSize - currentIdx))
        {
            for (unsigned int i = 0; i < noOfElements; ++i)
            {
                int newElement = heapArray[currentIdx];
                int k = currentIdx++;

                while (k > 0U && compareElementsByHeapType(newElement, heapArray[(k - 1U) / 2U]))
                {
                    int tempElement = heapArray[(k - 1U) / 2U];
                    heapArray[(k - 1U) / 2U] = newElement;
                    heapArray[k] = tempElement;
                    k = (k - 1U) / 2U;
                }
            }

            if (currentIdx == storageSize)
            {
                currentIdx--;
            }
        }
        else
        {
            std::cout << "[Insert()]: Heap capacity exceeded." << std::endl;
        }
    }

    // Deletion can only occur on the root node/first element of the heap.
    // In case of the MAX_HEAP this is the highest value, in case of
    // MIN_HEAP this is the lowest value.
    // Time complexity -> o(n * logn)
    // Space complexity -> o(1)
    [[nodiscard]] int Heap::Delete()
    {
        int deletedData = INT_MIN;

        if (currentIdx > 0U)
        {
            deletedData = heapArray[0U];
            heapArray[0U] = heapArray[currentIdx];
            heapArray[currentIdx--] = deletedData;

            unsigned int i = 0U;
            unsigned int j = (2U * i) + 1U;
            unsigned int tempData = INT_MIN;

            while (j < currentIdx)
            {
                if(compareElementsByHeapType(heapArray[j + 1U], heapArray[j]))
                {
                    j = j + 1U;
                }
                
                if (compareElementsByHeapType(heapArray[j], heapArray[i]))
                {
                    std::swap(heapArray[i], heapArray[j]);
                    i = j;
                    j = (2 * i) + 1U;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            std::cout << "[Delete()]: The heap is empty." << std::endl;
        }

        return deletedData;
    }

    // Time complexity -> o(1)
    // Space complexity-> o(1)
    [[nodiscard]] unsigned int Heap::StorageSize() const
    {
        return storageSize;
    }

    // Time complexity -> o(1)
    // Space complexity-> o(1)
    [[nodiscard]] unsigned int Heap::Size() const
    {

        return currentIdx;
    }

    // Time complexity -> o(n^2 * logn)
    // Space complexity -> o(1)
    // NOTE: for some reason when the heap is of type MAX_HEAP the HeapSort needs one iteration less 
    // when Insert() in comparison with Heapify()
    void Heap::HeapSort()
    {
        for (int i = currentIdx - 1U; i > 0L; --i)
        {
            (void)Delete(); // o(n * logn)
            std::cout << "i = " << i << ", currentIdx = " << currentIdx << " heap: " << *this << std::endl;
        }
    }

    // Time complexity -> o(n)
    // Space complexity-> o(1)
    std::ostream& operator<<(std::ostream& os, const Heap& heap)
    {
        os << "[OUT<<]: Heap: ";

        for (unsigned int i = 0; i < heap.storageSize; ++i)
        {
            os << heap.heapArray[i] << " ";
        }

        return os;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Heap::compareElementsByHeapType(const int a, const int b)
    {
        switch(type)
        {
            case HeapType::MAX_HEAP:
                return a > b;
            case HeapType::MIN_HEAP:
            default:
                return a < b;
        }
    }
}