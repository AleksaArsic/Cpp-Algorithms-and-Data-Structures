#include <iostream>

int factorial(const unsigned int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}

// nCr = n! / (r! * (n - r)!)
// Time complexity 
// n + n + n + 1 = 3n + 1 -> o(n)
unsigned int nCrWithoutRecursion(const unsigned int n, const unsigned int r)
{
    unsigned int numerator, denominator;

    numerator = factorial(n);      // -> o(n)
    denominator = factorial(r) * factorial(n - r);  // -> o(2n)

    return numerator / denominator;  // 1 (const)
}
// Can be calculated trough the Pascals triangle 
// https://en.wikipedia.org/wiki/Pascal%27s_triangle
// nCr = (n-1)C(r-1) + (n-1)C(r)
// Time complexity -> 
// when the function is calling it self two times it is 
// approximated to the o(2^n)
unsigned int nCr(const unsigned int n, const unsigned int r)
{
    if(r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}


int main()
{
    unsigned int n = 5;
    unsigned int r = 3;

    std::cout << "nCr for n = " << n << ", and r = " << r << " is equal to: " << nCr(n, r) << std::endl;
    std::cout << "nCr for n = " << n << ", and r = " << r << " is equal to: " << nCrWithoutRecursion(n, r) << std::endl;

    return 0;
}