#include <iostream>

// n! = 1 * 2 * 3 * ... * (n - 1) * n
// fact(n) = fact(n - 1) * n, n > 0
// fact(n) = 1, n = 0
// not defined for negative numbers
unsigned int factorialOfNNumbers(const unsigned int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return factorialOfNNumbers(n - 1) * n;
    }
}

unsigned int factorialOfNNumbersWithoutRecursion(const unsigned int n)
{
    unsigned int result = 1;
    for(unsigned int i = 1; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    unsigned int n = 3;
    unsigned int m = 10;
    unsigned int k = 12;

    std::cout << "Factorial of " << n << " with recursion is equal to: " << factorialOfNNumbers(n) << std::endl;
    std::cout << "Factorial of " << m << " with recursion is equal to: " << factorialOfNNumbers(m) << std::endl;
    std::cout << "Factorial of " << k << " with recursion is equal to: " << factorialOfNNumbers(k) << std::endl;

    std::cout << "Factorial of " << n << " natural numbers is equal to: " << factorialOfNNumbersWithoutRecursion(n) << std::endl;
    std::cout << "Factorial of " << m << " natural numbers is equal to: " << factorialOfNNumbersWithoutRecursion(m) << std::endl;
    std::cout << "Factorial of " << k << " natural numbers is equal to: " << factorialOfNNumbersWithoutRecursion(k) << std::endl;

    return 0;
}