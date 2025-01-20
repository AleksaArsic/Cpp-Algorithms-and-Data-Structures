#include <iostream>
#include <memory>

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

class Element final
{
    public:
        Element()
        {
            i = 0;
            j = 0;
            x = 0;
        }

        Element(unsigned int i, unsigned int j, int x) : i(i), j(j), x(x)
        { }

        void setI(unsigned int value) 
        {
            i = value;
        }

        void setJ(unsigned int value) 
        {
            j = value;
        }

        void setX(unsigned int value) 
        {
            x = value;
        }

        [[nodiscard]] unsigned int getI() const
        {
            return i;
        }

        [[nodiscard]] unsigned int getJ() const
        {
            return j;
        }

        [[nodiscard]] int getX() const
        {
            return x;
        }

    private:
        unsigned int i;
        unsigned int j;
        int x;

};

class SparseMatrix final
{
    public:
        SparseMatrix() = delete;

        SparseMatrix(unsigned int sizeN, unsigned int sizeM) : n(sizeN), m(sizeM)
        {
            nonZeroNum = 0;
            elements = nullptr;//std::make_unique<Element[]>(1);
        }

        void setElement(const Element& e)
        {
            if(e.getI() < n && e.getJ() < m)
            {
                int elementIndex = elementExists(e);
                if(elementIndex != -1L)
                {
                    std::cout << "Element (" << e.getI() << ", " << e.getJ() << ") exists, change value" << std::endl;
                    elements[elementIndex].setX(e.getX());
                    return;
                }
                else
                {
                    std::unique_ptr<Element[]> newNonZeroElements = std::make_unique<Element[]>(nonZeroNum + 1);

                    for(unsigned int i = 0; i < nonZeroNum; ++i)
                    {
                        newNonZeroElements[i] = elements[i];
                    }

                    newNonZeroElements[nonZeroNum] = e;
                    nonZeroNum = nonZeroNum + 1;

                    elements = std::move(newNonZeroElements);
                }
            }
        }

        [[nodiscard]] Element& getElement(unsigned int i, unsigned int j) const
        {
            for(unsigned int k = 0; k < nonZeroNum; ++k)
            {
                if(elements[k].getI() == i && elements[k].getJ() == j)
                {
                    return elements[k];
                }
            }
        }

        SparseMatrix operator+(const SparseMatrix& sm)
        {
            if(n != sm.n || m != sm.m)
            {
                return SparseMatrix(0,0);
            }

            SparseMatrix result(n, m);

            unsigned int i = 0, j = 0;

            while(i < nonZeroNum || j < sm.nonZeroNum)
            {
                if(elements[i].getI() < sm.elements[j].getI())
                {
                    result.setElement(elements[i++]);
                }
                else if(elements[i].getI() > sm.elements[j].getI())
                {
                    result.setElement(sm.elements[j++]);
                }
                else
                {
                    if(elements[i].getJ() < sm.elements[j].getJ())
                    {
                        result.setElement(elements[i++]);
                    }
                    else if(elements[i].getJ() > sm.elements[j].getJ())
                    {
                        result.setElement(sm.elements[j++]);
                    }
                    else
                    {
                        result.setElement(Element(elements[i].getI(), elements[i].getJ(), elements[i].getX() + sm.elements[j].getX()));
                        i++;
                        j++;
                    }
                }
            }

            for(; i < nonZeroNum; ++i)
            {
                result.setElement(elements[i]);
            }

            for(; j < sm.nonZeroNum; ++j)
            {
                result.setElement(sm.elements[j]);
            }

            return result;

        }

        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& sm);

    private:
        unsigned int n;
        unsigned int m;
        unsigned int nonZeroNum;
        std::unique_ptr<Element[]> elements;

        [[nodiscard]] int elementExists(const Element& e) const
        {
            for(unsigned int i = 0; i < nonZeroNum; ++i)
            {
                if(elements[i].getI() == e.getI() && elements[i].getJ() == e.getJ())
                {
                    return i;
                }
            }

            return -1L;
        }

};

std::ostream& operator<<(std::ostream& os, const SparseMatrix& sm)
{
    unsigned int k = 0;
    for(unsigned int i = 0; i < sm.n; ++i)
    {
        for(unsigned int j = 0; j < sm.m; ++j)
        {
            if(sm.elements[k].getI() == i && sm.elements[k].getJ() == j)
            {
                os << sm.elements[k++].getX() << " ";
            }
            else
            {
                os << 0L << " ";
            }
        }
        os << std::endl;
    }

    return os;
}

int main()
{
    SparseMatrix A(8, 9);

    A.setElement(Element(0, 0, 3));
    A.setElement(Element(1, 2, 8));
    A.setElement(Element(1, 5, 7));
    A.setElement(Element(1, 7, 3));
    A.setElement(Element(3, 0, 4));
    A.setElement(Element(5, 2, 2));
    A.setElement(Element(6, 3, 6));
    A.setElement(Element(7, 1, 9));
    A.setElement(Element(7, 4, 5));

    SparseMatrix B(8, 9);

    B.setElement(Element(0, 0, 3));
    B.setElement(Element(0, 1, 3));
    B.setElement(Element(0, 2, 3));
    B.setElement(Element(1, 2, 8));
    B.setElement(Element(1, 5, 7));
    B.setElement(Element(1, 7, 3));
    B.setElement(Element(3, 0, 4));
    B.setElement(Element(5, 2, 2));
    B.setElement(Element(6, 3, 6));

    std::cout << A << std::endl;
    std::cout << B << std::endl;

    std::cout << A + B << std::endl;

    return 0;
}