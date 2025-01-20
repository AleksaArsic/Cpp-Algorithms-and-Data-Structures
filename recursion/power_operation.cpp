#include <iostream>

// x^n is x multiplied n times
// x^n = x_1 * x_2 * x_3 * ... * x_(n-1) * x_n
// pow(x, n) = pow(x, n - 1) * x, n > 0
// pow(x, n) = 1, n = 0
int power(int x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return power(x, n - 1) * x;
    }
}

// x^n is x multiplied n times
// x^n = x_1 * x_2 * x_3 * ... * x_(n-1) * x_n
// pow(x, n) = pow(x * x, n / 2), n % 2 == 0
// pow(x, n) = x * pow(x * x, n / 2), n % 2 != 0
// pow(m, n) = 1, n == 0
// Time complexity -> o(n + 1) = o(n)
// Space complexity -> o(n + 1) = o(n)
int powerOptimized(int x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power(x * x, n / 2);
    }
    else
    {
        return x * power(x * x, (n - 1) / 2);
    }
}

int powerWithoutRecursion(int x, unsigned int n)
{
    int result = 1;

    for(int i = 0; i < n; ++i)
    {
        result *= x;
    }

    return result;
}

int main()
{
    int x = -4;
    unsigned int n = 3;
    unsigned int m = 10;
    unsigned int k = 12;

    std::cout << "Basic recursion" << std::endl;
    std::cout << x << " on the power of " << n << " with recursion is equal to: " << power(x, n) << std::endl;
    std::cout << x << " on the power of " << m << " with recursion is equal to: " << power(x, m) << std::endl;
    std::cout << x << " on the power of " << k << " with recursion is equal to: " << power(x, k) << std::endl;

    std::cout << "Optimized recursion" << std::endl;
    std::cout << x << " on the power of " << n << " with recursion is equal to: " << powerOptimized(x, n) << std::endl;
    std::cout << x << " on the power of " << m << " with recursion is equal to: " << powerOptimized(x, m) << std::endl;
    std::cout << x << " on the power of " << k << " with recursion is equal to: " << powerOptimized(x, k) << std::endl;

    std::cout << "Without recursion" << std::endl;
    std::cout << x << " on the power of " << n << " natural numbers is equal to: " << powerWithoutRecursion(x, n) << std::endl;
    std::cout << x << " on the power of " << m << " natural numbers is equal to: " << powerWithoutRecursion(x, m) << std::endl;
    std::cout << x << " on the power of " << k << " natural numbers is equal to: " << powerWithoutRecursion(x, k) << std::endl;

    return 0;
}