#include <iostream>

int main()
{
    int A[3][5]; // stack 2d array
    int* B[3];   // 1st dimension is on stack, 2nd on heap
                 // 3 elements of type pointer to integer are created
                 // on the stack
                 // allocating them into arrays, creates arrays on the heap
    int** C;     // heap 2d array

    A[2][5] = 3;
    std::cout << A[2][5] << std::endl;

    B[0] = new int[5];
    B[1] = new int[5];
    B[2] = new int[5];

    B[0][3] = 1;

    std::cout << B[0][3] << std::endl;

    C = new int*[3];
    C[0] = new int[5];
    C[1] = new int[5];
    C[2] = new int[5];

    C[0][3] = 3;

    std::cout << C[0][3] << std::endl;

    delete []B[0];
    delete []B[1];
    delete []B[2];

    delete []C;

    return 0; 
}