#include <iostream>
#include <memory>

// Diagonal matrix has the non-zero elements only
// on indices where i == j.
// Because of that we can store it in a single dimension array.
// Diagonal matrix is a square matrix with dimensions nxn
class DiagonalMatrix
{
    public:
        DiagonalMatrix()
        {
            n = DEFAULT_SIZE;
            dataContainer = std::make_unique<int[]>(DEFAULT_SIZE);
        }

        DiagonalMatrix(const unsigned int size) : n(size)
        {
            dataContainer = std::make_unique<int[]>(size);
        }

        void Set(unsigned int i, unsigned int j, int x)
        {
            if(i == j)
            {
                dataContainer[i] = x;
            }
        }

        [[nodisicard]] int Get(unsigned int i, unsigned int j) const
        {
            if(i == j)
            {
                return dataContainer[i];
            }
            else
            {
                return 0;
            }
        }

        void Display()
        {
            for(unsigned int i = 0; i < n; ++i)
            {
                for(unsigned int j = 0; j < n; ++j)
                {
                    if(i == j)
                    {
                        std::cout << dataContainer[i] << " ";
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
        std::unique_ptr<int[]> dataContainer;
        unsigned int n;
        static constexpr unsigned int DEFAULT_SIZE = 10;       
};

int main()
{
    constexpr int matrixSize = 5;
    DiagonalMatrix matrix(matrixSize);
    int data = 3;

    for(unsigned int i = 0; i < matrixSize; ++i)
    {
        for(unsigned int j = 0; j < matrixSize; ++j)
        {
            if(i == j)
            {
                matrix.Set(i, j, data);
                data += 3;
            }
        }
    }

    matrix.Display();
    std::cout << matrix.Get(3, 3);

    return 0;
}