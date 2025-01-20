#pragma once
#include <string>
#include <string_view>
#include "LinkedListStack.hpp"

std::string infixToPostfixConversion(std::string_view expression);
std::string infixToPostfixConversionSecond(std::string_view expression);
std::string infixToPostfixConversionThird(std::string_view expression);
std::string infixToPostfixConversionAdvanced(std::string_view expression);

std::string evaluatePostfixExpression(std::string_view expression);
