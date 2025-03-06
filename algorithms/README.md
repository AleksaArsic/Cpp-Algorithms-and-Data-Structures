# Algorithms

## Criteria for analysing sorting algorithms

The following are the criteria for analysing sorting algorithms:
1. Number of comparisons 
2. Number of swaps
3. Adaptive - the algorithm takes less time if the data is already sorted
4. Stable - means that the data is sorted based on the multiple parameters (e.g. name, grade), and the data will keep order
if any duplicates
5. Extra memory - determines if the algorithm takes extra memory for its execution

## Asymptotic notations

Asymptotic notations are used as a metric to describe the efficiency of algorithms.

Time complexity - a way of showing how the runtime of a function increases as the size of input increases.
Space complexity - a way of showing how the runtime memory consumption increases as the size of the input increases.
                 - measure of amount of a working storage that the algorithm needs.

```
1 < logn < n < n * logn < n^2 < n^3 < ... < 2^n < 3^n < ... < n^n < n!
```

There are three types of asymptotic notations:
- Lower bound - big Theta (at least more than best case)
- Upper bound - big O     (<= worst case)
- Tight bound - big Theta (average case - within bounds of the worst and best case)

When analysing time or space complexities we can use three mentioned notations to 
define the time/space behavior of the set of instructions, function, method, or algorithm. 

Big Theta is used when we want to define the lower bound of the mathematical function.
Big O is used when we want to define the upper bound of the mathematical function.
Big Theta is used when we want to define the exact, or tight bound of the mathematical function.

Example:
```
f(x) = Sum(i, i * 2^i), where i = 1, 2, ..., n

Asymptotic notation:
big Theta (2^n)
big O (n * 2^n)
big Theta (n * 2^n)
```

Rules for determining Big O notation:
```
Rule   | Description                                                                                              | Complexity 
---    | ---                                                                                                      | --- 
Rule 1 | Any assignment statements and if statements that are executed once regardless of the size of the problem | O(1) 
Rule 2 | A simple "for" loop from 0 to 'n' (without internal loops)                                               | O(n) 
Rule 3 | A nested loop of the same type takes quadratic time complexity                                           | O(n^2) 
Rule 4 | A loop, in which the controlling parameter is divided by two at each step. log with base 2.              | O(logn) 
Rule 5 | When dealing with multiple statements, add them up                                                       | --- 
```

### O(1) example
```
f(x) = x * x

int squareNumber(const int x)
{
    return x * x;
}

Time taken for this to execute is constant - multiply two numbers. That means that the time 
complexity is O(1).
```

### O(n) example
```
f(x) = Sum(x), x = 0, 1, 2, ..., n 

int sum(const int x)
{
    int sum = 0;

    for(unsigned int i = 0; i < x; ++i)
    {
        sum += i;
    }

    return sum;
}

Time taken for the function to execute is dependent on the number x, i.e. on the number of iterations
of the for loop. That means that the time complexity is O(n).
```

### Drop constants
```
void print(const int x)
{
    for(unsigned int i = 0; i < x; ++i)
    {
        std::cout << i << " ";
    }

    for(unsigned int j = 0; j < x; ++j)
    {
        std::cout << j << " ";
    }
}

Degree of polynomial is what matters, the constant does not.
Time complexity -> O(n) + O(n) -> O(2n) = O(n)
```

### O(n^2) example
```
void print(const int x)
{
    for(unsigned int i = 0; i < x; ++i)
    {
        for(unsigned int j = 0; j < x; ++j)
        {
            std::cout << "(" << i << ", " << j << ") ";
        }
    }
}

Time taken for the function to execute depends on two nested for loops. This means that for 'n' numbers
the inner loop will execute 'n' times. That leads us to the O(n^2).
In terms of big O notation it does not matter if there are 3-4-5 nested loops,
the time can be represented as O(n^2).
```

### Drop non-dominant terms
```
void print(const int x)
{
    for(unsigned int i = 0; i < x; ++i)
    {
        for(unsigned int j = 0; j < x; ++j)
        {
            std::cout << "(" << i << ", " << j << ") ";
        }
    }

    for(unsigned int k = 0; k < x; ++k)
    {
        std::cout << k << " ";
    }
}

Degree of polynomial is what matters, the constant and non-dominant term does not.
Time complexity -> O(n^2) + O(n) -> O(n^2 + n) = O(n^2)
```

### O(logn) example
```
In a given sorted array find the element x = 1:

1 2 3 4 5 6 7 8

Divide and conquer method:
- Divide the array into two parts 
- Check in which part 1 should be, discard the other
- 1 2 3 4 (5 6 7 8)
- Divide the array into two parts
- Check in which part 1 should be, discard the other
- 1 2 (3 4)
- Divide the array into two parts
- Check in which part 1 should be, discard the other
- 1 (2)
- x = 1 is found

Three iterations were needed to find the element with this method. 

2^3 = 8
2 -> array is split into two parts
3 -> iterations
8 -> number of elements

log(8) = 3 -> log with base 2

Therefore the time taken for the method to execute is O(logn). Log with base 2.
```

### Space Complexity
```
int sum(const int x)
{
    if(n <= 0L)
    {
        return 0L;
    }

    return n + sum(n - 1);
}

If x = 3, the recursive call will populate the stack as follows:
- sum(1)
- sum(2)
- sum(3)

Therefore the space complexity of this function will be O(n), as it needs 'n' amount of space on stack.
```

### Different Terms for Input - Add vs Multiply

```
void print(const int x, const int y)
{
    for(unsigned int i = 0; i < x; ++i)
    {
        std::cout << i << " ";
    }

    for(unsigned int j = 0; j < y; ++j)
    {
        std::cout << j << " ";
    }
}

Time complexity is **not** O(n). We cannot say that the x = n, y = n, instead we need to **add** them.
Therefore, the time complexity is equal to O(x + y).
```
```
void print(const int x, const int y)
{
    for(unsigned int i = 0; i < x; ++i)
    {
        for(unsigned int j = 0; j < y; ++j)
        {
            std::cout << "(" << i << ", " << j << ") ";
        }
    }
}

Time complexity is **not** O(n^2). We cannot say that the x = n, y = n, instead we need to **multiply** them.
Therefore, the time complexity is equal to O(x * y).
```