#include <iostream>

// Every recursion can be implemented as a loop

// There are several types of recursions:
// 1. Tail recursion
// 2. Head recursion
// 3. Tree recursion
// 4. Indirect recursion
// 5. Nested recursion

// Time complexity o(n) -> order of n
// Space complexity o(n) -> order of n
// Can be easily converted in a simple while loop with time complexity o(n), and
// space complexity o(1)
void tailRecursion(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        tailRecursion(n - 1); // last statement in the function is a call to it self
                              // all processing is done at calling time
    }
}

// Time complexity o(n) -> order of n
// Space complexity o(n) -> order of n
// Cannot be easily converted into a loop (but it can be converted)
void headRecursion(int n)
{
    if (n > 0)
    {
        headRecursion(n - 1); // first statement in the function is a call to it self
                              // all processing is done in returning time
        std::cout << n << " ";
    }
}

// If the function calls it self only once, it is called Linear recursion
// If the function calls it self several time, it is called Tree recursion
// Time complexity -> 2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1) - 1 = o(2^n)
// Space complexity -> maximum size of stack
// Space complexity -> o(n + 1) = o(n)
void treeRecursion(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// There are several functions calling each other
// A calls -> B, B calls -> C, C calls -> A
void funA(int n);
void funB(int n);

void indirectRecursion(int n)
{
    funA(n);
}

void funA(int n)
{
    if(n > 0)
    {
        std::cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if(n > 1)
    {
       std::cout << n << " ";
       funA(n / 2); 
    }
}

// Nested recursion is a recursion that has a recursion call within a recursion call
// e.g. fun(fun(n - 1))
int nestedRecursion(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return nestedRecursion(nestedRecursion(n + 11));
    }
}

int main()
{
    int x = 5;
    int y = 3;
    int z = 20;
    int k = 95;

    std::cout << "tailRecursion(" << x << ") = ";
    tailRecursion(x);
    std::cout << std::endl;

    std::cout << "headRecursion(" << x << ") = ";
    headRecursion(x);
    std::cout << std::endl;

    std::cout << "treeRecursion(" << y << ") = ";
    treeRecursion(y);
    std::cout << std::endl;

    std::cout << "indirectRecursion(" << z << ") = ";
    indirectRecursion(z);
    std::cout<< std::endl;

    std::cout << "nestedRecursion(" << k << ") = " << nestedRecursion(k) << std::endl;

    return 0;
}