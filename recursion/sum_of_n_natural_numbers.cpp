#include <iostream>

// sum(n) = 1 + 2 + 3 ... + (n-1) + n
// sum(n) = 0, if n == 0
// sum(n) = sum(n - 1) + n, if n > 0
// Formula (without recursion): sum(n) = n(n + 1) / 2
unsigned int sumOfNNaturalNumbers(const unsigned int n)
{
    if(n >= 1)
    {
        return sumOfNNaturalNumbers(n - 1) + n;
    }
    else
    {
        return 0;
    }
}

unsigned int sumOfNNaturalNumbersWithoutRecursion(const unsigned int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    unsigned int n = 3;
    unsigned int m = 10;
    unsigned int k = 100;

    std::cout << "Sum of first " << n << " natural numbers with recursion is equal to: " << sumOfNNaturalNumbers(n) << std::endl;
    std::cout << "Sum of first " << m << " natural numbers with recursion is equal to: " << sumOfNNaturalNumbers(m) << std::endl;
    std::cout << "Sum of first " << k << " natural numbers with recursion is equal to: " << sumOfNNaturalNumbers(k) << std::endl;

    std::cout << "Sum of first " << n << " natural numbers is equal to: " << sumOfNNaturalNumbersWithoutRecursion(n) << std::endl;
    std::cout << "Sum of first " << m << " natural numbers is equal to: " << sumOfNNaturalNumbersWithoutRecursion(m) << std::endl;
    std::cout << "Sum of first " << k << " natural numbers is equal to: " << sumOfNNaturalNumbersWithoutRecursion(k) << std::endl;

    return 0;
}