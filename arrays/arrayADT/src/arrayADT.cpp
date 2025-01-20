#include "arrayADT.h"

namespace arrayADT
{
    // Maybe not the best way to utilize templates
    // Experimenting with templates
    // Tells the compiler to instantiate class template of named type
    // this way we can define the template class methods inside of .cpp file
    // Resources: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

	template class arrayADT<char>;
	template class arrayADT<int>;
	template class arrayADT<unsigned int>;
	template class arrayADT<long>;
	template class arrayADT<long long>;
	template class arrayADT<float>;
	template class arrayADT<double>;

    template<typename T> requires isANumber<T>
    arrayADT<T>::arrayADT(const unsigned int size, const unsigned int length, const std::initializer_list<T>& list) : size(size), length(length)
    {
        container = std::make_shared<T[]>(size);

        try
        {
            if (list.size() != length)
            {
                throw InitializerListAndLengthNotEqual(list.size(), length);
            }

            auto it = std::begin(list);
            for (int i = 0; i < length; ++i)
            {
                container[i] = *(it++);
            }
        }
        catch (const InitializerListAndLengthNotEqual& exception)
        {
            std::cerr << exception.what() << std::endl;
        }
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::Display() const noexcept
    {
        for (int i = 0; i < length; ++i)
        {
            std::cout << container[i] << " ";
        }
        std::cout << std::endl;
    }

    // Time complexity -> o(1)
    // f(n) = 1 -> f(n) = 1 * n^0 -> o(1)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::Append(const int x)
    {
        if (length == size)
        {
            std::cout << "[Append] FAILED: Not enough space." << std::endl;
        }
        else
        {
            container[length++] = x;
        }
    }

    // Time complexity -> min o(1) -> no elements need to be shifted, index = length
    // Time complexity -> max o(n) -> all elements need to be shifted, index = 0
    template<typename T> requires isANumber<T>
    void arrayADT<T>::Insert(const unsigned int index, const int x)
    {
        if (length == size)
        {
            std::cout << "[Insert] FALIED: Not enough space." << std::endl;
        }
        else
        {
            for (unsigned int i = length; i > index; --i)
            {
                container[i] = container[i - 1];
            }

            container[index] = x;
            length++;
        }
    }

    // Time complexity -> min o(1) -> no elements need to be shifted, index = length
    // Time complexity -> max o(n) -> all elements need to be shifted, index = 0
    template<typename T> requires isANumber<T>
    void arrayADT<T>::Delete(const unsigned int index)
    {
        if (index >= length)
        {
            std::cout << "[Delete] FAILED: Index out of range." << std::endl;
        }
        else
        {
            for (unsigned int i = index; i < length; ++i)
            {
                container[i] = container[i + 1];
            }

            length--;
        }
    }
    
    // This can be done with two for loops with the time complexity 
    // o(n) as well
    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::Reverse()
    {
        for (int i = 0, j = length - 1; i < j; ++i, --j)
        {
            std::swap(container[i], container[j]);
        }
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::LeftShift()
    {
        for (int i = 1; i < length; ++i)
        {
            container[i - 1] = container[i];
        }

        container[length - 1] = 0;
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::RightShift()
    {
        for (int i = length - 1; i > 0; --i)
        {
            container[i] = container[i - 1];
        }

        container[0] = 0;
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::LeftRotate()
    {
        T firstEl = container[0];

        for (int i = 1; i < length; ++i)
        {
            container[i - 1] = container[i];
        }

        container[length - 1] = firstEl;
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::RightRotate()
    {
        T lastEl = container[length - 1];

        for (int i = length - 1; i > 0; --i)
        {
            container[i] = container[i - 1];
        }

        container[0] = lastEl;
    }

    // Time complexity -> o(1)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::SetElement(const unsigned int index, const T element)
    {
        if (index < length)
        {
            container[index] = element;
        }
    }

    // Time complexity -> o(1)
    template<typename T> requires isANumber<T>
    T arrayADT<T>::GetElement(const unsigned int index) const
    {
        if (index < length)
        {
            return container[index];
        }      

    }

    // Time complexity -> f(n) = 2n + 1 -> o(n)
    template<typename T> requires isANumber<T>
    T arrayADT<T>::GetMaxElement() const
    {
        T max = container[0]; // 1

        for (int i = 1; i < length; ++i) // n
        {
            if (max <= container[i])    // n - 1
            {
                max = container[i];
            }
        }

        return max; // 1
    }

    // Time complexity -> f(n) = 2n + 1 -> o(n)
    template<typename T> requires isANumber<T>
    T arrayADT<T>::GetMinElement() const
    {
        T min = container[0]; // 1

        for (int i = 1; i < length; ++i) // n
        {
            if (min >= container[i])    // n - 1
            {
                min = container[i];
            }
        }

        return min; // 1
    }

    // Time complexity -> f(n) = recirsive calls of RGetElementSum -> o(n)
    template<typename T> requires isANumber<T>
    T arrayADT<T>::GetElementSum() const
    {
        return RGetElementSum(length - 1);
    }

    // Time complexity -> f(n) = recirsive calls of RGetElementSum -> o(n)
    template<typename T> requires isANumber<T>
    double arrayADT<T>::GetElementAvg() const
    {
        return static_cast<double>(RGetElementSum(length - 1)) / length;
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    bool arrayADT<T>::IsSortedAscending() const
    {
        for (int i = 0; i < length - 1; ++i)
        {
            if (container[i] > container[i + 1])
            {
                return false;
            }
        }

        return true;
    }

    // Time complexity -> o(n)
    template<typename T> requires isANumber<T>
    bool arrayADT<T>::IsSortedDescending() const
    {
        for (int i = 0; i < length - 1; ++i)
        {
            if (container[i] < container[i + 1])
            {
                return false;
            }
        }

        return true;
    }

    template<typename T> requires isANumber<T>
    void arrayADT<T>::PlaceNegativeLeft()
    {
        int i = 0;
        int j = length - 1;

        while (i < j)
        {
            while (container[i] < 0) { i++; }
            while (container[j] >= 0) { j--; }

            if (i < j) std::swap(container[i], container[j]);
        }
    }

    // Arrays need to be sorted
    // Modifies the original object!
    // Time complexity -> Theta(n + m)
    template<typename T> requires isANumber<T>
    void arrayADT<T>::MergeArray(const arrayADT<T>& array)
    {
        std::shared_ptr<T[]> mergedContainerPtr = std::make_shared<T[]>(size + array.size);

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;

        while (i < length && j < array.length)
        {
            if (container[i] < array.container[j])
            {
                mergedContainerPtr[k++] = container[i++];
            }
            else
            {
                mergedContainerPtr[k++] = array.container[j++];
            }
        }

        for (; i < length; ++i)
        {
            mergedContainerPtr[k++] = container[i];
        }

        for (; j < array.length; ++j)
        {
            mergedContainerPtr[k++] = array.container[j];
        }

        container = mergedContainerPtr;
        size = size + array.size;
        length = length + array.length;
    }

    // Modifies the original object!
    // Can be performed on sorter or unsorted array
    template<typename T> requires isANumber<T>
    void arrayADT<T>::OperationUnion(const arrayADT<T>& array)
    {
        std::shared_ptr<T[]> newArrayPtr = std::make_shared<T[]>(size + array.size);
        unsigned int newArraySize = 0;
        bool areArraysSorted[2] = { IsSortedAscending(), array.IsSortedAscending() };

        if (areArraysSorted[0] == true && areArraysSorted[1] == true)
        {
            // Sorted arrays logic
            // Time complexity -> o(n)
            unsigned int i = 0;
            unsigned int j = 0;
            unsigned int k = 0;

            while (i < length && j < array.length)
            {
                // keep the order sorted
                if (container[i] < array.container[j])
                {
                    newArrayPtr[k++] = container[i++];
                }
                else if (container[i] > array.container[j])
                {
                    newArrayPtr[k++] = array.container[j++];
                }
                else
                {
                    newArrayPtr[k++] = container[i++];
                    j++;
                }
            }

            for (; i < length; ++i)
            {
                newArrayPtr[k++] = container[i];
            }

            for (; j < array.length; ++j)
            {
                newArrayPtr[k++] = array.container[j];
            }

            newArraySize = k;
        }
        else
        {
            // Unsorted arrays logic
            // Time complexity -> o(n^2)
            unsigned int k = 0;
            
            for (unsigned int i = 0; i < length; ++i)
            {
                newArrayPtr[k++] = container[i];
            }

            newArraySize = k;
            bool foundDuplicate = false;

            for (unsigned int i = 0; i < array.length; ++i)
            {
                for (unsigned int j = 0; j < newArraySize; ++j)
                {
                    if (array.container[i] == newArrayPtr[j])
                    {
                        foundDuplicate = true;
                        continue;
                    }
                }

                if (!foundDuplicate)
                {
                    newArrayPtr[newArraySize] = array.container[i];
                    newArraySize++;
                }

                foundDuplicate = false;
            }
        }

        container = newArrayPtr;
        size = size + array.size;
        length = newArraySize;
    }

    // Modifies the original object!
    template<typename T> requires isANumber<T>
    void arrayADT<T>::OperationIntersection(const arrayADT<T>& array)
    {
        std::shared_ptr<T[]> newArrayPtr = std::make_shared<T[]>(size + array.size);
        unsigned int newArraySize = 0;
        bool areArraysSorted[2] = { IsSortedAscending(), array.IsSortedAscending() };

        if (areArraysSorted[0] == true && areArraysSorted[1] == true)
        {
            // Sorted arrays logic
            // Time complexity -> o(n)
            unsigned int i = 0;
            unsigned int j = 0;
            unsigned int k = 0;

            while (i < length && j < array.length)
            {
                if (container[i] == array.container[j])
                {
                    newArrayPtr[k++] = container[i];
                }
                i++;
                j++;
            }

            newArraySize = k;
        }
        else
        {
            // Unsorted arrays logic
            // Time complexity -> o(n^2)
            unsigned int k = 0;

            for (unsigned int i = 0; i < length; ++i)
            {
                for (unsigned int j = 0; j < array.length; ++j)
                {
                    if (container[i] == array.container[j])
                    {
                        newArrayPtr[k++] = container[i];
                        break;
                    }
                }
            }

            newArraySize = k;
        }

        container = newArrayPtr;
        size = size + array.size;
        length = newArraySize;
    }

    // Modifies the original object!
    // Extract the elements that are only in A but not in B
    template<typename T> requires isANumber<T>
    void arrayADT<T>::OperationDifference(const arrayADT<T>& array)
    {
        std::shared_ptr<T[]> newArrayPtr = std::make_shared<T[]>(size + array.size);
        unsigned int newArraySize = 0;
        bool areArraysSorted[2] = { IsSortedAscending(), array.IsSortedAscending() };

        if (areArraysSorted[0] == true && areArraysSorted[1] == true)
        {
            // Sorted arrays logic
            // Time complexity -> o(n)
            unsigned int i = 0;
            unsigned int j = 0;
            unsigned int k = 0;

            while (i < length && j < array.length)
            {
                if (container[i] > array.container[j])
                {
                    j++;
                }
                else if (container[i] < array.container[j])
                {
                    newArrayPtr[k++] = container[i];
                    i++;
                }
                else
                {
                    i++;
                    j++;
                }
            }

            for (; i < length; ++i)
            {
                newArrayPtr[k++] = container[i];
            }

            newArraySize = k;
        }
        else
        {
            // Unsorted arrays logic
            // Time complexity -> o(n^2)
            bool foundDuplicate = false;
            unsigned int k = 0;

            for (unsigned int i = 0; i < length; ++i)
            {
                for (unsigned int j = 0; j < length; ++j)
                {
                    if (container[i] == array.container[j])
                    {
                        foundDuplicate = true; 
                        break;
                    }
                }

                if (!foundDuplicate)
                {
                    newArrayPtr[k++] = container[i];
                }

                foundDuplicate = false;
            }

            newArraySize = k;
        }

        container = newArrayPtr;
        size = size + array.size;
        length = newArraySize;
    }

    // Time complexity -> min o(1) -> first element is found as the key
    // Time complexity -> min o(n) -> last element is found as the key
    // Time complexity -> avg o(n) -> (1 + 2 + 3 + 4 + ... + n) / n = (n(n+1)/2) / n = (n + 1) / 2
    template<typename T> requires isANumber<T>
    int arrayADT<T>::LinearSearch(const T key) const
    {
        for (unsigned int i = 0; i < length; ++i)
        {
            if(container[i] == key)
            {
                return i;
            }
        }

        return -1;
    }

    template<typename T> requires isANumber<T>
    int arrayADT<T>::LinearSearchTransposition(const T key)
    {
        for (unsigned int i = 0; i < length; ++i)
        {
            if(container[i] == key)
            {
                if(i > 0)
                {
                    std::swap(container[i], container[i - 1]);
                    return i - 1;
                }
                else
                {
                    return 0;
                }
            }
        }

        return -1;
    }

    template<typename T> requires isANumber<T>
    int arrayADT<T>::LinearSearchMoveToHead(const T key) 
    {
        for (unsigned int i = 0; i < length; ++i)
        {
            if(container[i] == key)
            {
                std::swap(container[i], container[0]);
                return 0;
                
            }
        }

        return -1;
    }

    // For Binary search the data container needs to be sorted
    // Time complexity -> depends on the hight of the tree
    // Time complexity -> min -> o(1) -> if the searched elements is at the center of the array
    // Time complexity -> max -> e.g. number of elements is 16
    //                        -> 16 / 2 / 2 / 2 / 2 = 1
    //                        -> 16 / 2^4 = 1
    //                        -> 2^4 = 16
    //                        -> log2(16) = 4
    //                        -> o(log(n))
    template<typename T> requires isANumber<T>
    int arrayADT<T>::BinarySearch(const T key) const
    {
        int low = 0;
        int high = length - 1;
        int mid = -1;

        while(low <= high)
        {
            mid = (low + high) / 2; // floored value

            if(key == container[mid])
            {
                return mid;
            }
            else if(key < container[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }

    // For Binary search the data container needs to be sorted
    // Time complexity -> depends on the hight of the tree
    // Time complexity -> min -> o(1) -> if the searched elements is at the center of the array
    // Time complexity -> max -> e.g. number of elements is 16
    //                        -> 16 / 2 / 2 / 2 / 2 = 1
    //                        -> 16 / 2^4 = 1
    //                        -> 2^4 = 16
    //                        -> log2(16) = 4
    //                        -> o(log(n))
    template<typename T> requires isANumber<T>
    int arrayADT<T>::BinarySearchRecursive(const T key) const
    {
        return RBinarySearch(0, length - 1, key);
    }

    template<typename T> requires isANumber<T>
    int arrayADT<T>::RBinarySearch(const unsigned int low, const unsigned int high, const T key) const
    {
        int mid = (low + high) / 2;

        if(low <= high)
        {
            if(key == container[mid])
            {
                return mid;
            }
            else if (key < container[mid])
            {
                return RBinarySearch(low, mid - 1, key);
            }
            else
            {
                return RBinarySearch(mid + 1, high, key);
            }
        }

        return -1;
    }

    // Time complexity -> f(n) = 2n + 1 -> o(n)
    template<typename T> requires isANumber<T>
    T arrayADT<T>::RGetElementSum(const unsigned int idx) const
    {
        if (idx == 0)
        {
            return container[0];
        }
        else
        {
            return RGetElementSum(idx - 1) + container[idx];
        }
    }

	template<typename T> requires isANumber<T>
	arrayADT<T>::InitializerListAndLengthNotEqual::InitializerListAndLengthNotEqual(const int listSize, const int arrayLength)
	{
		buildErrorMessage(listSize, arrayLength);
	}

	template<typename T> requires isANumber<T>
	const char* arrayADT<T>::InitializerListAndLengthNotEqual::what() const noexcept
	{
		return errorMessage.c_str();
	}

	template<typename T> requires isANumber<T>
	void arrayADT<T>::InitializerListAndLengthNotEqual::buildErrorMessage(const int listSize, const int arrayLength)
	{
		errorMessage = "Initializer list size and array length are not the same. ";
		errorMessage += "Expected array length = " + std::to_string(arrayLength) + " ";
		errorMessage += "Actual initializer list size = " + std::to_string(listSize) + " ";
	}

}