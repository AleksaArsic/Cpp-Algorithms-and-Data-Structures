#pragma once
#include <iostream>
#include <memory>

namespace PolynomialRepresentation
{
    struct Data final
    {
        int coefficient;
        int exponent;
    };

    struct Node final
    {
        struct Data data;
        std::shared_ptr<Node> next;
    };

    class Polynomial final
    {
        public:
            Polynomial();
            Polynomial(const std::shared_ptr<Node> node);

            Polynomial(const unsigned int highestExp, const std::shared_ptr<int[]> arrayOfElements);

            double Evaluate(const double x);

            friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
            friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

        private:
            std::shared_ptr<Node> head;
    };
}