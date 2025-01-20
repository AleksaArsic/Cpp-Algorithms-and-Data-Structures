#include "PolynomialRepresentation.hpp"
#include <cmath>

namespace PolynomialRepresentation
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Polynomial::Polynomial() : head(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Polynomial::Polynomial(const std::shared_ptr<Node> node) : head(node)
    {  }

    // Time complexity -> o(n)
    // Space complexity -> o(n)
    Polynomial::Polynomial(const unsigned int highestExp, const std::shared_ptr<int[]> arrayOfElements)
    {
        std::shared_ptr<Node> newNode;
        std::shared_ptr<Node> node;

        head = std::make_shared<Node>(Data(arrayOfElements[highestExp], highestExp), nullptr);
        node = head;

        for (int i = highestExp - 1; i >= 0; --i)
        {
            newNode = std::make_shared<Node>(Data(arrayOfElements[i], i), nullptr);
            node->next = newNode;
            node = node->next;
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    double Polynomial::Evaluate(const double x)
    {
        double result = 0;
        std::shared_ptr<Node> node = head;

        while (node != nullptr)
        {
            result += (node->data.coefficient * std::pow(x, node->data.exponent));
            node = node->next;
        }
        
        return result;
    }

    // Time complexity -> min -> o(1)
    // Time complexity -> max -> o(n)
    // Space complexity -> o(1)
    Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
    {
        if (p1.head != nullptr && p2.head != nullptr)
        {
            unsigned int highestExponentPolyOne = p1.head->data.exponent;
            unsigned int highestExponentPolyTwo = p2.head->data.exponent;

            std::shared_ptr<Node> nodePolyOne = p1.head;
            std::shared_ptr<Node> nodePolyTwo = p2.head;

            std::shared_ptr<Node> resPolyHead = nullptr;
            std::shared_ptr<Node> resPolyNode = nullptr;
            std::shared_ptr<Node> newNode;

            while (nodePolyOne != nullptr && nodePolyTwo != nullptr)
            {
                if (nodePolyOne->data.exponent > nodePolyTwo->data.exponent)
                {
                    // first greater than second
                    // take first
                    newNode = std::make_shared<Node>(Data(nodePolyOne->data.coefficient, nodePolyOne->data.exponent), nullptr);
                    nodePolyOne = nodePolyOne->next;
                }
                else if (nodePolyOne->data.exponent < nodePolyTwo->data.exponent)
                {
                    // second greater than first
                    // take second
                    newNode = std::make_shared<Node>(Data(nodePolyTwo->data.coefficient, nodePolyTwo->data.exponent), nullptr);
                    nodePolyTwo = nodePolyTwo->next;
                }
                else
                {
                    // equal - add them
                    newNode = std::make_shared<Node>(Data(nodePolyOne->data.coefficient + nodePolyTwo->data.coefficient, 
                                                                                nodePolyOne->data.exponent), nullptr);
                    nodePolyOne = nodePolyOne->next;
                    nodePolyTwo = nodePolyTwo->next;
                }

                if (resPolyHead == nullptr)
                {
                    resPolyHead = newNode;
                    resPolyNode = resPolyHead;
                }
                else
                {
                    resPolyNode->next = newNode;
                    resPolyNode = resPolyNode->next;
                }
            }

            while (nodePolyOne != nullptr)
            {
                newNode = std::make_shared<Node>(Data(nodePolyOne->data.coefficient, nodePolyOne->data.coefficient), nullptr);
                resPolyHead->next = newNode;
                nodePolyOne = nodePolyOne->next;
            }

            while (nodePolyTwo != nullptr)
            {
                newNode = std::make_shared<Node>(Data(nodePolyTwo->data.coefficient, nodePolyTwo->data.coefficient), nullptr);
                resPolyHead->next = newNode;
                nodePolyTwo = nodePolyTwo->next;
            }

            
            return Polynomial(resPolyHead);
        }
        else if (p1.head == nullptr)
        {
            return p2;
        }
        else if (p2.head == nullptr)
        {
            return p1;
        }
        else
        {
            return Polynomial();
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Polynomial& p)
    {
        if (p.head != nullptr)
        {
            std::shared_ptr<Node> node = p.head;

            while (node->next != nullptr)
            {
                os << node->data.coefficient << "x^" << node->data.exponent << " + ";
                node = node->next;
            }

            os << node->data.coefficient << "x^" << node->data.exponent;
        }
        
        return os;
    }
}