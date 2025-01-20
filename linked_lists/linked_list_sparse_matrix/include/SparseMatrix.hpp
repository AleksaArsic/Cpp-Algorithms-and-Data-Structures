#pragma once
#include <iostream>
#include <vector>

namespace SparseMatrix
{
    struct Coordinates final
    {
        unsigned int i;
        unsigned int j;
    };

    struct Node final
    {
        Coordinates coordinates;
        int data;
        std::shared_ptr<Node> next;
    };

    class SparseMatrix final
    {
        public:
            SparseMatrix();

            void createMatrix(const unsigned int nSize, const unsigned int mSize, const std::vector<std::vector<int>>& matrix);
            void addElement(const unsigned int i, const unsigned int j, const int data);            
            
            friend std::ostream& operator<<(std::ostream & os, SparseMatrix & sm);

        private:
            unsigned int n;
            unsigned int m;
            std::vector<std::shared_ptr<Node>> rows;

            [[nodiscard]] std::shared_ptr<Node>& rewindList(std::shared_ptr<Node>& rowHead);
    };
}