#include <iostream>
#include <memory>

// Symetric matrix is a matrix where the following
// property is true: M[i][j] = M[j][i]
// We can store it as a Lower Triangular matrix or 
// Upper Triangular matrix.

// Lower triangular matrix has the non-zero elements only
// on indices where i >= j.
// Because of that we can store it in a single dimension array.
// Lower triangular matrix is a square matrix with dimensions nxn
// Element access can be done row-wise or column wise
// The size of the array needed to store the non-zero elements is 
// equal to: n(n + 1) / 2
class LowerTriangularMatrix
{
    public:
        LowerTriangularMatrix()
        {
            unsigned int sizeOfMatrix = (DEFAULT_SIZE * (DEFAULT_SIZE + 1)) / 2;
            n = DEFAULT_SIZE;
            dataContainer = std::make_unique<int[]>(sizeOfMatrix);
        }

        LowerTriangularMatrix(const unsigned int size)
        {
            unsigned int sizeOfMatrix = (size * (size + 1)) / 2;
            n = size;
            dataContainer = std::make_unique<int[]>(sizeOfMatrix);
        }

        void Set(unsigned int i, unsigned int j, int x)
        {
            if(i >= j)
            {
                // Row wise access
                //dataContainer[calculateRowWiseIndex(i, j)] = x;
                // Column wise access
                dataContainer[calculateColumnWiseIndex(i, j)] = x;
            }
        }

        [[nodisicard]] int Get(const unsigned int i, const unsigned int j) const
        {
            if(i >= j)
            {
                // Row wise access
                //return dataContainer[calculateRowWiseIndex(i, j)];
                // Column wise access
                return dataContainer[calculateColumnWiseIndex(i, j)];
            }
            else
            {
                // Row wise access
                //return dataContainer[calculateRowWiseIndex(j, i)];
                // Column wise access
                return dataContainer[calculateColumnWiseIndex(j, i)];
            }
        }

        void Display()
        {
            for(unsigned int i = 0; i < n; ++i)
            {
                for(unsigned int j = 0; j < n; ++j)
                {
                    if(i >= j)
                    {
                        // Row wise access
                        //std::cout << dataContainer[calculateRowWiseIndex(i, j)] << " ";
                        // Column wise access
                        std::cout << dataContainer[calculateColumnWiseIndex(i, j)] << " ";
                    }
                    else
                    {
                        // Row wise access
                        //std::cout << dataContainer[calculateRowWiseIndex(j, i)] << " ";
                        // Column wise access
                        std::cout << dataContainer[calculateColumnWiseIndex(j, i)] << " ";
                    }
                }
                std::cout << std::endl;
            }
        }

    private:
        std::unique_ptr<int[]> dataContainer;
        unsigned int n;
        static constexpr unsigned int DEFAULT_SIZE = 10;       

        unsigned int calculateRowWiseIndex(const unsigned int i, const unsigned int j) const
        {
            return ((i * (i + 1)) / 2) + j;
        }

        unsigned int calculateColumnWiseIndex(const unsigned int i, const unsigned int j) const 
        {
            return ((n * j) - ((j * (j - 1) / 2))) + (i - j);
        }
};

int main()
{
    constexpr int matrixSize = 5;
    LowerTriangularMatrix matrix(matrixSize);
    int data = 1;

    for(unsigned int i = 0; i < matrixSize; ++i)
    {
        for(unsigned int j = 0; j < matrixSize; ++j)
        {
            if(i >= j)
            {
                matrix.Set(i, j, data);

                data += 1;
            }
        }

        data = 1;
    }

    matrix.Display();
    std::cout << matrix.Get(2, 3) << std::endl;
    std::cout << matrix.Get(3, 2) << std::endl;

    return 0;
}