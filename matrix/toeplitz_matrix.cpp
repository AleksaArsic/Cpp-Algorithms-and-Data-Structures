#include <iostream>
#include <memory>

// Toeplitz matrix is the matrix with the property
// that the each elements on diagonal are equal
// M[i][j] = M[i - 1][j - 1]

class ToeplitzMatrix
{
    public:
        ToeplitzMatrix()
        {
            unsigned int matrixSize = calculateSizeOfMatrix(DEFAULT_SIZE);
            n = DEFAULT_SIZE;
            dataContainer = std::make_unique<int[]>(matrixSize);
        }

        ToeplitzMatrix(unsigned int size) : n(size)
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
            return 2L * size - 1L;
        }

        [[nodiscard]] int calculateIndex(const int i, const int j) const
        {
            if(i <= j)
            {
                return j - i;
            }
            else if(i > j)
            {
                return n - 1L + i - j;
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
    ToeplitzMatrix matrix(matrixSize);
    int data = 1;

    for(unsigned int i = 0; i < 1; ++i)
    {
        for(unsigned int j = 0; j < matrixSize; ++j)
        {
            matrix.Set(i, j, data);
            data += 1;
        }
    }

    for(unsigned int i = 1; i < matrixSize; ++i)
    {
        for(unsigned int j = 0; j < 1; ++j)
        {
            matrix.Set(i, j, data);
        }

        data += 1;
    }

    matrix.Display();
    std::cout << "Get(1, 2): " << matrix.Get(1, 2) << std::endl;
    std::cout << "Get(3, 4): " << matrix.Get(3, 4) << std::endl;
    std::cout << "Get(2, 2): " << matrix.Get(2, 2) << std::endl;

    return 0;
}