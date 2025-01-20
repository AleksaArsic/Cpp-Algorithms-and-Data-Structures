#include <iostream>
#include <memory>
#include <vector>
#include "SparseMatrix.hpp"

void printVectorMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (auto it = std::begin(matrix); it != std::end(matrix); ++it)
    {
        for (auto it2 = std::begin(*it); it2 != std::end(*it); ++it2)
        {
            std::cout << *it2 << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    constexpr unsigned int n = 5;
    constexpr unsigned int m = 7;

    std::vector<std::vector<int>> matrix = { {1, 0, 0, 5, 0, 0, 3},
                                                {0, 0, 0, 0, 0, 0, 0},
                                                {-8, 0, 0, 12, 0, 0, 0},
                                                {0, 2, 0, 0, 1, 0, 18},
                                                {0, 0, 0, -5, 0, 0, 0},
                                              };

    std::cout << "Sparse Matrix [vector of vectors]: " << std::endl;
    printVectorMatrix(matrix);

    SparseMatrix::SparseMatrix sparseMatrix;
    sparseMatrix.createMatrix(n, m, matrix);

    std::cout << "Sparse Matrix [SparseMatrixClass]: " << std::endl;
    std::cout << sparseMatrix << std::endl;

    sparseMatrix.addElement(1, 4, 18);
    sparseMatrix.addElement(1, 2, 6);
    sparseMatrix.addElement(2, 0, 8);
    sparseMatrix.addElement(3, 6, -8);
    sparseMatrix.addElement(4, 6, 1);
    sparseMatrix.addElement(4, 0, 1);

    std::cout << "Sparse Matrix [SparseMatrixClass] Add element: " << std::endl;
    std::cout << sparseMatrix << std::endl;

    return 0;
}