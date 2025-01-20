#include <iostream>

// Time complexity -> o(n)
void findMissingElement(const unsigned int size, const unsigned int* array)
{
    unsigned int diff = array[0] - 0; // lowest element - first index

    for(unsigned int i = 0; i < size; ++i)
    {
        if(array[i] - i != diff)
        {
            std::cout << "Missing element is: " << diff + i << std::endl;
            break;
        }
    }
}

// Time complexity -> o(n)
unsigned int recursiveSumOfNumbers(const unsigned int* array, const unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return recursiveSumOfNumbers(array, n - 1) + array[n - 1]; 
    }
}

// Sum of n natural numbers: sum(n) = n(n + 1) / 2
// Time complexity -> o(n)
unsigned int findMissingElementInNNaturalNumbers(const unsigned int size, const unsigned int* array)
{
    unsigned int sumOfArray = recursiveSumOfNumbers(array, size);
    unsigned int sum = (array[size - 1] * (array[size - 1] + 1)) / 2;

    return sum - sumOfArray;
}

int main()
{
    constexpr unsigned int n = 10;
    unsigned int arrayOfNumbers[n] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    unsigned int arrayOfNumbersTwo[n] = {7, 8, 9, 10, 11, 13, 14, 15, 16, 17};

    std::cout << "Missing number in the "<< arrayOfNumbers[n] << " natural numbers is:" << 
                    findMissingElementInNNaturalNumbers(n, arrayOfNumbers) << std::endl;

    findMissingElement(n, arrayOfNumbersTwo);

    return 0;
}