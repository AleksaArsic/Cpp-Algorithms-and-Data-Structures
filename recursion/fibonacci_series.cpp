#include <iostream>
#include <algorithm>

// Fibonacci series -> excessive recursion example
// 0 1 1 2 3 5 8 13 -> value
// 0 1 2 3 4 5 6 7  -> index
// fib(n) = 0, n = { 0 }
// fib(n) = 1, n = { 1, 2 }
// fib(n) = fib(n - 1) + fib(n - 2), n > 2
// Time complexity:
// We need to approximate that the function is calling it self two times
// 2 * fib(n - 1)
// When the function calls it self two times the time complexity is o(2^n)
unsigned long long fibonacciSeries(const unsigned int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
    }
}

// Fibonacci series -> memoization method (with lookup table)
// 0 1 1 2 3 5 8 13 -> value
// 0 1 2 3 4 5 6 7  -> index
// Time complexity:
// For fib(5) there are 6 calls
// For fib(7) there are 8 calls
// time complexity -> n + 1 
// time complexity -> o(n)
constexpr int MAXIMAL_FIBONACCI_N = 100;
long long lookupTable[MAXIMAL_FIBONACCI_N];

unsigned long long fibonacciSeriesOptimized(const unsigned int n)
{
    if(n <= 1)
    {
        lookupTable[n] = n;
        return n;
    }
    else
    {
        if(lookupTable[n - 1] == -1)
        {
            lookupTable[n - 1] = fibonacciSeriesOptimized(n - 1);
        }
        if(lookupTable[n - 2] == -1)
        {
            lookupTable[n - 2] = fibonacciSeriesOptimized(n - 2);
        }

        return lookupTable[n - 1] + lookupTable[n - 2];
    }
}


// Fibonacci series 
// 0 1 1 2 3 5 8 13 -> value
// 0 1 2 3 4 5 6 7  -> index
// Time complexity -> o(n)
// Time complexity:
// line 45 -> n-1
// lines 49 - 51 -> n + n + n
// time complexity -> 4n - 1 ~ o(n)
unsigned long long fibonacciSeriesWithoutRecursion(const unsigned int n)
{
    long long t0, t1;
    long long result = 1L;

    if(n <= 1)
    {
        return n;
    }

    t0 = 0;
    t1 = 1;
    for(int i = 2; i <= n; ++i)
    {
        result = t0 + t1;
        t0 = t1;
        t1 = result; 
    }

    return result;
}

int main()
{
    unsigned int n = 10;

    std::fill_n(lookupTable, MAXIMAL_FIBONACCI_N, -1);

    std::cout << "Fibonacci series of n = " << n << " is equal to: " << fibonacciSeries(n) << std::endl;
    std::cout << "Fibonacci series of n = " << n << " is equal to: " << fibonacciSeriesOptimized(n) << std::endl;
    std::cout << "Fibonacci series of n = " << n << " is equal to: " << fibonacciSeriesWithoutRecursion(n) << std::endl;
    return 0;
}