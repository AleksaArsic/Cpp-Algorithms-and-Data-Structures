#include <iostream>

void printArray(const int* const arrayPtr, size_t arraySize)
{
    for(int i = 0; i < arraySize; ++i)
    {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int* arrayPtr = new int[5];

    arrayPtr[0] = 1;
    arrayPtr[1] = 2;
    arrayPtr[2] = 3;
    arrayPtr[3] = 4;
    arrayPtr[4] = 5;

    int* newArrayPtr = new int[10];

    printArray(arrayPtr, 5);

    for(int i = 0; i < 5; ++i)
    {
        newArrayPtr[i] = arrayPtr[i];
    }

    printArray(newArrayPtr, 10);
    
    delete[] arrayPtr;
    arrayPtr = newArrayPtr;
    newArrayPtr = nullptr;

    //printArray(newArrayPtr, 10); // invalid
    printArray(arrayPtr, 5);

    return 0;
}