#include <iostream>

// Sparse matrices are matrices that have non-zero elements 
// on random places. Therefore, there is no general formula on where
// the non-zero elements can be found like in symetric, toeplitz,
// and/or diagonal matrices.
// There are two methods which we can use to store the non-zero elements
// and reducing the space needed for the sparse matrix.
//
// First method - Coordinate list representation:
// Storing there columns:
//    1) Row - stores row index of non-zero element
//    2) Column - stores column index of non-zero element
//    3) Element - stores the element it self
//
// Index 0 of all three columns is reserved for storing the number of elements 
// of each column.
//
// Second method - Compressed sparse rows:
// Storing three arrays:
//    1) A  - stores non-zero elements in the same order they are appearing
//    2) IA - array of rows. Stores the number of elements in the current row + the value of the 
//            previous row. Accumulates the number of elements in the rows.
//    3) JA - array of columns. Stores the column in which the element of A is stored in the matrix.
//
// For example if we have a sparse matrix that stores integers with dimensions of 8x9, 
// and with 8 non-zero elements.
// For storing this kind of matrix we need 72*width_of_int bytes (if width of int is 4 bytes than 72*4).
// If we use Compressed sparse rows we need (8 + 9 (no of rows + 1) + 8) * width_of_int (if width of int is 4 bytes than 50*4)

template <typename Matrix>
int calculateNonZeroElements(const int sizeN, const int sizeM, const Matrix& sparseMatrix)
{
    int noOfNonZeroElements = 0;
    
    for(unsigned int i = 0; i < sizeN; ++i)
    {
            for(unsigned int j = 0; j < sizeM; ++j)
            {
                if(sparseMatrix[i][j] > 0)
                {
                    noOfNonZeroElements++;
                }
            }
    }

    return noOfNonZeroElements;
}

template <typename Matrix>
void demonstrateFirstMethod(const int sizeN, const int sizeM, Matrix& sparseMatrix)
{
    int noOfNonZeroElements = calculateNonZeroElements(sizeN, sizeM, sparseMatrix);

    if(noOfNonZeroElements == 0)
    {
        std::cout << "All elements are non-zero." << std::endl;
        return;
    }
    else
    {
        std::cout << "Number of non-zero elemets: " << noOfNonZeroElements << std::endl;
    }

    // Storing there columns:
    //    1) Row - stores row index of non-zero element
    //    2) Column - stores column index of non-zero element
    //    3) Element - stores the element it self
    int matrix[3][noOfNonZeroElements + 1];

    matrix[0][0] = sizeN;
    matrix[1][0] = sizeM;
    matrix[2][0] = noOfNonZeroElements;
    int elementCnt = 1; // first column is for sizeN, sizeM and noOfNonZeroElements

    for(unsigned int i = 0; i < sizeN; ++i)
    {
        for(unsigned int j = 0; j < sizeM; ++j)
        {
            if(sparseMatrix[i][j] != 0)
            {
                matrix[0][elementCnt] = i;
                matrix[1][elementCnt] = j;
                matrix[2][elementCnt] = sparseMatrix[i][j];
                elementCnt++;
            }
        }
    }
    
    for(unsigned int i = 0; i < 3; ++i)
    {
        for(unsigned int j = 0; j < noOfNonZeroElements + 1; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

template <typename Matrix>
void demonstrateSecondMethod(const int sizeN, const int sizeM, Matrix& sparseMatrix)
{
    int noOfNonZeroElements = calculateNonZeroElements(sizeN, sizeM, sparseMatrix);

    if(noOfNonZeroElements == 0L)
    {
        std::cout << "All elements are non-zero." << std::endl;
        return;
    }
    else
    {
        std::cout << "Number of non-zero elemets: " << noOfNonZeroElements << std::endl;
    }

    // Storing three arrays:
    //    1) A  - stores non-zero elements in the same order they are appearing
    //    2) IA - array of rows. Stores the number of elements in the current row + the value of the 
    //            previous row. Accumulates the number of elements in the rows.
    //    3) JA - array of columns. Stores the column in which the element of A is stored in the matrix.
    int A[noOfNonZeroElements];
    int iA[noOfNonZeroElements + 1];
    int jA[noOfNonZeroElements];

    iA[0] = 0;

    int noOfElementsInARow = 0;
    int elementCnt = 0;

    for(unsigned int i = 0; i < sizeN; ++i)
    {
        for(unsigned int j = 0; j < sizeM; ++j)
        {
            if(sparseMatrix[i][j] != 0)
            {
                A[elementCnt] = sparseMatrix[i][j];
                jA[elementCnt] = j;
                elementCnt++;
                noOfElementsInARow++;
            }
        }

        iA[i + 1] = iA[i] + noOfElementsInARow;
        noOfElementsInARow = 0;
    }

    for(unsigned int i = 0; i < noOfNonZeroElements; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    for(unsigned int i = 0; i < noOfNonZeroElements + 1; ++i)
    {
        std::cout << iA[i] << " ";
    }
    std::cout << std::endl;

    for(unsigned int i = 0; i < noOfNonZeroElements; ++i)
    {
        std::cout << jA[i] << " ";
    }
    std::cout << std::endl;
}

template <typename Matrix>
void populateMatrixWithZeros(const int sizeN, const int sizeM, Matrix& matrix)
{
    for(unsigned int i = 0; i < sizeN; ++i)
    {
        for(unsigned int j = 0; j < sizeM; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

template <typename Matrix>
void displayMatrix(const int sizeN, const int sizeM, const Matrix& matrix)
{
    for(unsigned int i = 0; i < sizeN; ++i)
    {
        for(unsigned int j = 0; j < sizeM; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }    
}

int main()
{
    constexpr int sizeN = 8;
    constexpr int sizeM = 9;
    int sparseMatrix[sizeN][sizeM];

    populateMatrixWithZeros(sizeN, sizeM, sparseMatrix);

    sparseMatrix[0][7] = 3;
    sparseMatrix[1][2] = 8;
    sparseMatrix[1][5] = 10;
    sparseMatrix[3][0] = 4;
    sparseMatrix[5][2] = 2;
    sparseMatrix[6][3] = 6;
    sparseMatrix[7][1] = 9;
    sparseMatrix[7][4] = 5;

    std::cout << "Initial {full scaled} sparse matrix: " << std::endl;
    displayMatrix(sizeN, sizeM, sparseMatrix);

    std::cout << "First method sparse matrix: " << std::endl;
    demonstrateFirstMethod(sizeN, sizeM, sparseMatrix);

    std::cout << "Compressed sparse row method matrix: " << std::endl;
    demonstrateSecondMethod(sizeN, sizeM, sparseMatrix);

    return 0;
}