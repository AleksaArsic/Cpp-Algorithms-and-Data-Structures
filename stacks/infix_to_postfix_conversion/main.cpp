#include <iostream>
#include <string>
#include <string_view>
#include "LinkedListStack.hpp"
#include "LinkedListStackTest.hpp"
#include "InfixToPostfix.hpp"

int main()
{
    LinkedListStack::Stack stack;
    std::string expression = "a + b * c - d / e";
    std::string expressionAdvanced = "((a + b) * c) - d ^ e ^ f";
    std::string expressionToEval = "3 5 * 6 2 / + 4 -";

    testStack(stack);

    std::cout << infixToPostfixConversion(expression) << std::endl;
    std::cout << infixToPostfixConversionSecond(expression) << std::endl;
    std::cout << infixToPostfixConversionThird(expression) << std::endl;
    std::cout << infixToPostfixConversionAdvanced(expressionAdvanced) << std::endl;

    std::cout << "Evaluate -> 3 5 * 6 2 / + 4 - = " << evaluatePostfixExpression(expressionToEval) << std::endl;

    return 0;
}