#include <iostream>

int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n;
    }

    return 0;
}

// static variables are created in the code section of memory
// in the particular code section reserved for static and global variables
int fun2(int n)
{
    static int x = 0;

    if (n > 0)
    {
        x++;
        return fun2(n - 1) + x;
    }

    return 0;
}

// global variables are created in the code section of memory
// in the particular code section reserved for static and global variables
int c = 0;

int fun3(int n)
{
    if (n > 0)
    {
        c++;
        return fun3(n - 1) + c;
    }

    return 0;
}


int main()
{
    int a = 5;

    // fun(5) = 5 + 4 + 3 + 2 + 1 = 15
    std::cout << fun(a) << std::endl;
    
    // fun2(5) = fun2(4) + x = 20 + 5 = 25
    //       x = 5 
    // fun2(4) = fun2(3) + x = 15 + 5 = 20
    // fun2(3) = fun2(2) + x = 10 + 5 = 15
    // fun2(2) = fun2(1) + x = 5 + 5 = 10
    // fun2(1) = fun2(0) + x = 0 + 5 = 5
    // fun2(0) = 0
    std::cout << fun2(a) << std::endl;

    // fun3(5) = fun3(4) + c = 20 + 5 = 25
    //       c = 5 
    // fun3(4) = fun3(3) + c = 15 + 5 = 20
    // fun3(3) = fun3(2) + c = 10 + 5 = 15
    // fun3(2) = fun3(1) + c = 5 + 5 = 10
    // fun3(1) = fun3(0) + c = 0 + 5 = 5
    // fun3(0) = 0
    std::cout << fun3(a) << std::endl;

    return 0;
}