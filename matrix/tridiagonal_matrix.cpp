#include <iostream>
#include <memory>

// Tri-diagonal matrix is a matrix that 
// has adjacent diagonals to the main diagonal
// as non-zero elements
// The rest of the elements are zero.
// M[i][j] = non-zero, if |i - j| <= 1
// M[i][j] = 0, if |i - j| > 1
// The number of Non-zero elements is 3n - 2
// We can store only Non-zero elements in the 1D array
// in any order of lower, main and upper diagonal
// In this example we will store the diagonals in the following order:
// 1) Lower diagonal
// 2) Main diagonal
// 3) Upper diagonal
class TridiagonalMatrix
{
    public:
        TridiagonalMatrix()
        {
            unsigned int matrixSize = calculateSizeOfMatrix(DEFAULT_SIZE);
            n = DEFAULT_SIZE;
            dataContainer = std::make_unique<int[]>(matrixSize);
        }

        TridiagonalMatrix(unsigned int size) : n(size)
        {
            unsigned int matrixSize = calculateSizeOfMatrix(size);
            dataContainer = std::make_unique<int[]>(matrixSize);
        }

        void Set(const unsigned int i, const unsigned int j, int x)
        {
            int idx = calculateIndex(i, j);

            if(idx >= 0)
            {
                dataContainer[calculateIndex(i, j)] = x;
            }
        }

        [[nodiscard]] int Get(unsigned int i, unsigned int j) const
        {
            return dataContainer[calculateIndex(i, j)];
        }

        void Display() const
        {
            for(unsigned int i = 0; i < n; ++i)
            {
                for(unsigned int j = 0; j < n; ++j)
                {
                    int idx = calculateIndex(i, j);
                    if(idx >= 0)
                    {
                        std::cout << dataContainer[idx] << " ";
                    }
                    else
                    {
                        std::cout << 0L << " ";
                    }
                }

                std::cout << std::endl;
            }
        }

    private:
        static constexpr int DEFAULT_SIZE = 10;
        unsigned int n; 
        std::unique_ptr<int[]> dataContainer;

        [[nodiscard]] unsigned int calculateSizeOfMatrix(const unsigned int size) const
        {
            return 3L * size - 2L;
        }

        [[nodiscard]] int calculateIndex(const int i, const int j) const
        {
            if(i - j == 0L)
            {
                return n - 1L + i;
            }
            else if(i - j == 1L)
            {
                return i - 1;
            }
            else if(i - j == -1L)
            {
                return (2L * n) + (i - 1);
            }
            else
            {
                return -1L;
            }
        }

};

int main()
{
    constexpr int matrixSize = 5;
    TridiagonalMatrix matrix(matrixSize);
    int data = 1;

    for(unsigned int i = 0; i < matrixSize; ++i)
    {
        for(unsigned int j = 0; j < matrixSize; ++j)
        {
            matrix.Set(i, j, data);
        }
        data += 1;
    }

    matrix.Display();
    std::cout << matrix.Get(1, 2) << std::endl;

    return 0;
}