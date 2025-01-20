#include "SparseMatrix.hpp"

namespace SparseMatrix
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    SparseMatrix::SparseMatrix()
    {
        n = 0;
        m = 0;

        rows = std::vector<std::shared_ptr<Node>>(0);
    }

    // Time complexity -> o(n^2)
    // Space complexity -> o(n)
    void SparseMatrix::createMatrix(const unsigned int nSize, const unsigned int mSize, const std::vector<std::vector<int>>& matrix)
    {
        n = nSize;
        m = mSize;

        rows = std::vector<std::shared_ptr<Node>>(n);
        
        std::shared_ptr<Node> rowHead = nullptr;

        for (unsigned int i = 0; i < n; ++i)
        {
            rowHead = rewindList(rows[i]);
            
            for (unsigned int j = 0; j < m; ++j)
            {
                if (matrix[i][j] != 0L)
                {
                    std::shared_ptr<Node> newNode = std::make_shared<Node>(Coordinates(i, j), matrix[i][j], nullptr);

                    if (rowHead != nullptr)
                    {
                        rowHead->next = newNode;
                        rowHead = rowHead->next;
                    }
                    else
                    {
                        rowHead = newNode;
                        rows[i] = rowHead;
                    }
                }
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void SparseMatrix::addElement(const unsigned int i, const unsigned int j, const int data)
    {
        if (i < n && j < m)
        {
            std::shared_ptr<Node> rowHead = rows[i];
            std::shared_ptr<Node> newNode = nullptr;

            if (rowHead != nullptr)
            {
                std::shared_ptr<Node> tail = nullptr;

                while (rowHead != nullptr && rowHead->coordinates.j < j)
                {
                    tail = rowHead;
                    rowHead = rowHead->next;
                }

                if (rowHead != nullptr && rowHead->coordinates.j == j)
                {
                    rowHead->data += data;
                }
                else
                {
                    newNode = std::make_shared<Node>(Coordinates(i, j), data, rowHead);

                    if (tail == nullptr)
                    {
                        rows[i] = newNode;
                    }
                    else
                    {
                        tail->next = newNode;
                    }
                }
            }
            else
            {
                newNode = std::make_shared<Node>(Coordinates(i, j), data, nullptr);
                rows[i] = newNode;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::shared_ptr<Node>& SparseMatrix::rewindList(std::shared_ptr<Node>& rowHead)
    {
        if (rowHead != nullptr)
        {
            while (rowHead->next != nullptr)
            {
                rowHead = rowHead->next;
            }
        }
       
        return rowHead;
    }

    // Time complexity -> o(n^2)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, SparseMatrix& sm)
    {
        std::shared_ptr<Node> rowHead = nullptr;

        for (unsigned int i = 0; i < sm.n; ++i)
        {
            rowHead = sm.rows[i];
            for (unsigned int j = 0; j < sm.m; ++j)
            {
                if (rowHead != nullptr && i == rowHead->coordinates.i && j == rowHead->coordinates.j)
                {
                    os << rowHead->data << " ";
                    rowHead = rowHead->next;
                }
                else
                {
                    os << "0 ";
                }
            }
            os << std::endl;
        }

        return os;
    }
}