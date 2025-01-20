#include <iostream>

// factorial 
// n! = 1 * 2 * 3 * ... * (n - 1) * n
// n! = (n - 1)! * n
// fact(n) = fact (n - 1) * n , n > 0
// fact(n) = 1, n == 0
// Time complexity -> o(n)
// Space complexity -> o(n)
unsigned int factorial(const unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// m to the power of n
// pow(m, n) = m ^ n = m * m * m * ... * m (n times)
// pow(m, n) = pow(m * m, n / 2), n % 2 == 0
// pow(m, n) = m * pow(m * m, (n - 1) / 2), n % 2 != 0
// pow(m, n) = 1, n == 0
// Time complexity o(n / 2), n % 2 == 0
// Time complexity o((n + 1) / 2), n % 2 != 0
// Space complexity o(n / 2), n % 2 == 0
// Space complexity o((n + 1) / 2), n % 2 != 0
int power(const int m, const int n)
{
    if(n == 0)
    {
        return 1;
    }

    if(n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else
    {
        return m * power(m * m, (n - 1) / 2);
    }
}

// sum of N natural numbers
// sum(n) = 1 + 2 + 3 + ... + (n - 1) + n
// sum(n) = sum(n - 1) + n, n > 0
// sum(n) = 0, n = 0
// Time complexity -> o(n)
// Space complexity -> o(n)
unsigned int sumOfNNaturalNumbers(const unsigned int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return sumOfNNaturalNumbers(n - 1) + n;
    }
}

// Taylor series for the e^x
// e^x = 1 + x / 1 + x^2/ 2! + x^3 / 3! + x^4 / 4 + ... 
// n terms
// we can do this by combing the recursive functions of 
// sum of N natural numbers,
// m to the power of n, and
// n factorial 
double taylorSeriesEtoThePowerOfXNoRecursion(double x, const unsigned int n)
{
    double result = 0.0;

    for (int i = 0; i < n; ++i)
    {
        unsigned int denumerator = factorial(i);
        int numerator = power(x, i);
        result += static_cast<double>(numerator) / (denumerator);
    }

    return result;
}

// Time complexity -> O(n^2)
double taylorSeriesEtoThePowerOfX(const double x, const unsigned int n)
{
    static int p = 1;
    static unsigned int f = 1;
    double result; 

    if(n == 0)
    {
        return 1.0;
    }
    else
    {
        result = taylorSeriesEtoThePowerOfX(x, n - 1);
        p = p * x;
        f = f * n;
        double fraction = static_cast<double>(p) / f;
        return result + fraction;
    }
}

// Time complexity -> o(n) - linear
double taylorSeriesEtoThePowerOfXHornetsRule(const double x, const unsigned int n)
{
    static double res = 0;

    if(n == 0)
    {
        return res;
    }
    else
    {
        res = 1.0 + (x / n) * res;
        return taylorSeriesEtoThePowerOfXHornetsRule(x , n - 1);
    }
}

int main()
{
    double x = 1.0;
    unsigned int n = 10;

    std::cout << "Taylor series of the e^x for the x = " << x << " is equal to: " <<  taylorSeriesEtoThePowerOfXNoRecursion(x, n) << std::endl;
    std::cout << "Taylor series of the e^x for the x = " << x << " is equal to: " <<  taylorSeriesEtoThePowerOfXHornetsRule(x, n) << std::endl;
    std::cout << "Taylor series of the e^x for the x = " << x << " is equal to: " <<  taylorSeriesEtoThePowerOfX(x, n) << std::endl;

    return 0;
}