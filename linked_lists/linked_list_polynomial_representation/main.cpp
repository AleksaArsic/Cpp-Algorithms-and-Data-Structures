#include <iostream>
#include <memory>
#include <vector>
#include "PolynomialRepresentation.hpp"

int main()
{
    constexpr unsigned int highestExponentOne = 2;
    constexpr unsigned int highestExponentTwo = 8;

    std::shared_ptr<int[]> polynomialArrayOne(new int[] {13, 8, 19});//, 22, -5, -2, 0, 1, 12});
    std::shared_ptr<int[]> polynomialArrayTwo(new int[] {13, 8, 19, 22, -5, -2, 0, 1, 12});

    PolynomialRepresentation::Polynomial p1(highestExponentOne, polynomialArrayOne);
    PolynomialRepresentation::Polynomial p2(highestExponentTwo, polynomialArrayTwo);
    PolynomialRepresentation::Polynomial p3;

    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "Evaluation of p1 for the x = 2.0 is equal to: " << p1.Evaluate(2.0f) << std::endl;

    p3 = p1 + p2;

    std::cout << "p1 + p2 = " << p3 << std::endl;
    std::cout << "p2 + p1 = " << p2 + p1 << std::endl;

    std::cout << "empty = " <<  PolynomialRepresentation::Polynomial() << std::endl;
    std::cout << "p1 + empty = " <<  p1 + PolynomialRepresentation::Polynomial() << std::endl;
    std::cout << "empty + p2 = " <<  p2 + PolynomialRepresentation::Polynomial() << std::endl;

    return 0;
}