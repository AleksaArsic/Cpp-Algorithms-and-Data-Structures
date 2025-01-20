#include <iostream>

// Let L0 be the address of the first element of nD array
// Let w be the width of the array element (e.g. sizeof(int))
//
// Example: X[n][m][k]
//
// 1D array elements are accessed based on the following formula:
//      Addr(X[i]) = L0 + i * w
// 2D array elements are accessed based on the following formulas:
//      Row-wise access (C/C++):
//          Addr(X[i][j]) = L0 + (i * m + j) * w
//      Column-wise access:
//          Addr(X[i][j]) = L0 + (j * n + m) * w
// 3D array elements are accessed based on the following formulas:
//      Row-wise access (C/C++):
//          Addr(X[i][j][k]) = L0 + (i * m * l + j * l + k) * w
//      Column-wise access:
//          Addr(X[i][j][k]) = L0 + (k * m * n + j * n + i) * w
//
// We can observe the patterns
//      For row-wise access we are going from the left to right subscription wise
//      For column-wise access we are going from the right to left subscription wise

int main()
{
    int X[3][5][2] = { {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}, 
                       {{11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}}, 
                       {{21, 22}, {23, 24}, {25, 26}, {27, 28}, {29, 30}}};

    std::cout << "X[2][2][0]: " << X[2][2][0] << std::endl;
    std::cout << "*(*(*(X + 2) + 2) + 0): " << *(*(*(X + 2) + 2) + 0) << std::endl;
    std::cout << "*(*(*(X + 2) + 2) + 1): " << *(*(*(X + 2) + 2) + 1) << std::endl << std::endl;
    std::cout << "*(*(X + 2) + 2): " << *(*(X + 2) + 2) << std::endl;
    std::cout << "*(X + 2) + 2: " << *(X + 2) + 2 << std::endl;
    std::cout << "X + 2: " << X + 2 << std::endl;

    return 0;
}