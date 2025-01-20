#include "InfixToPostfix.hpp"

static bool checkIfOperand(const char c)
{
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

static bool checkIfOperandAdvanced(const char c)
{
    return ((c == '+') || (c == '-') || 
            (c == '*') || (c == '/') || 
            (c == '^') || (c == '(') || (c == ')'));
}

static bool checkIfCharacter(const char c)
{
    return ((c >= 'a') && (c <= 'z'));
}

static bool checkIfNumber(const char c)
{
    return ((c >= '0') && (c <= '9'));
}

static unsigned int checkPrecendance(const char c)
{
    if ((c == '+') || (c == '-'))
    {
        return 1U;
    }
    else if ((c == '*') || (c == '/'))
    {
        return 2U;
    }
    else if ((c >= 'a') || (c <= 'z'))
    {
        return 3U;
    }
    else
    {
        return UINT_MAX;
    }
}

static unsigned int inStackPrecedance(const char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 2U;
        case '*':
        case '/':
            return 4U;
        case '^':
            return 5U;
        case '(':
            return 0U;
        default:
            return UINT_MAX;
    }
}

static unsigned int outStackPrecedance(const char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1U;
        case '*':
        case '/':
            return 3U;
        case '^':
            return 6U;
        case '(':
            return 7U;
        case ')':
            return 0U;
        default:
            return UINT_MAX;
    }
}

static int doOperation(const char a, const char b, const char operation)
{
    int first = a - '0';
    int second = b - '0';

    switch (operation)
    {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
        default:
            return INT_MIN;
    }
}

// Time complexity -> o(n^2)
// Space complexity -> o(n) -> we need additional stack of maximal size = str.size();
std::string infixToPostfixConversion(std::string_view expression)
{
    std::string postfixExpression = "";
    LinkedListStack::Stack stack; 

    for (unsigned int i = 0; i < expression.size(); ++i)
    {
        switch (expression[i])
        {
            case '+':
            case '-':
                while (stack.stackTop().precedence >= 1)
                {
                    postfixExpression += stack.pop().character;
                }

                stack.push(expression[i], 1);
                break;
            case '*':
            case '/':
                while (stack.stackTop().precedence >= 2)
                {
                    postfixExpression += stack.pop().character;
                }

                stack.push(expression[i], 2);
                break;
            default:
                if (expression[i] != ' ' && (expression[i] >= 'a' && expression[i] <= 'z'))
                {
                    postfixExpression += expression[i];
                }
                break;
        }
    }

    while (!stack.isEmpty())
    {
        postfixExpression += stack.pop().character;
    }

    return postfixExpression;
}

// Time complexity -> o(n^2)
// Space complexity -> o(n) -> we need additional stack of maximal size = str.size();
std::string infixToPostfixConversionSecond(std::string_view expression)
{
    std::string postfixExpression = "";
    LinkedListStack::Stack stack;
    char precedence = 0;

    for (unsigned int i = 0; i < expression.size(); ++i)
    {
        switch (expression[i])
        {
        case '+':
        case '-':
            while (stack.stackTop().precedence >= 1)
            {
                postfixExpression += stack.pop().character;
            }

            stack.push(expression[i], 1);
            break;
        case '*':
        case '/':
            while (stack.stackTop().precedence >= 2)
            {
                postfixExpression += stack.pop().character;
            }

            stack.push(expression[i], 2);
            break;
        default:
            if (expression[i] != ' ' && (expression[i] >= 'a' && expression[i] <= 'z'))
            {
                while (stack.stackTop().precedence >= 3)
                {
                    postfixExpression += stack.pop().character;
                }

                stack.push(expression[i], 3);
            }
            break;
        }
    }

    while (!stack.isEmpty())
    {
        postfixExpression += stack.pop().character;
    }

    return postfixExpression;
}

// Time complexity -> o(n)
// Space complexity -> o(n) -> we need additional stack of maximal size = str.size();
std::string infixToPostfixConversionThird(std::string_view expression)
{
    std::string postfixExpression = "";
    LinkedListStack::Stack stack;
    unsigned int i = 0;

    while ((i < expression.size()))
    {
        if (checkIfOperand(expression[i]) || checkIfCharacter(expression[i]))
        {
            if (!stack.isEmpty() && stack.stackTop().precedence >= checkPrecendance(expression[i]))
            {
                postfixExpression += stack.pop().character;
            }
            else
            {
                stack.push(expression[i], checkPrecendance(expression[i]));
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }

    while (!stack.isEmpty())
    {
        postfixExpression += stack.pop().character;
    }

    return postfixExpression;
}

// Time complexity -> o(n)
// Space complexity -> o(n) -> we need additional stack of maximal size = str.size();
// This method uses two types of percedances:
//  --------------------------------------
// | Symbol | Out stack pre | In stack pre|
// |  +, -  |       1       |      2      | -> left to right operations have higher In stack pre
// |  *, /  |       3       |      4      |
// |   ^    |       6       |      5      | -> right to left operations have higher Out stack pre
// |   (    |       7       |      0      |
// |   )    |       0       |      ?      | -> closing brackets never go into the stack
//  --------------------------------------
// 
// With this method we can add as much operand as we want.
std::string infixToPostfixConversionAdvanced(std::string_view expression)
{
    std::string postfixExpression = "";
    LinkedListStack::Stack stack;
    unsigned int i = 0;

    while (i < expression.size())
    {
        if (checkIfOperandAdvanced(expression[i]))
        {
            if (!stack.isEmpty() && stack.stackTop().precedence >= outStackPrecedance(expression[i]))
            {
                if (stack.stackTop().precedence == outStackPrecedance(expression[i]))
                {
                    stack.pop().character;
                    ++i;
                }
                else
                {
                    postfixExpression += stack.pop().character;
                }
            }
            else
            {
                stack.push(expression[i], inStackPrecedance(expression[i]));
                ++i;
            }
        }
        else if (checkIfCharacter(expression[i]))
        {
            postfixExpression += expression[i++];
        }
        else
        {
            ++i;
        }
    }

    while (!stack.isEmpty())
    {
        postfixExpression += stack.pop().character;
    }

    return postfixExpression;
}

std::string evaluatePostfixExpression(std::string_view expression)
{
    LinkedListStack::Stack stack;
    unsigned int i = 0;

    while (i < expression.size())
    {
        if (checkIfNumber(expression[i]))
        {
            stack.push(expression[i++], 0);
        }
        else if (checkIfOperand(expression[i]))
        {
            char b = stack.pop().character;
            char a = stack.pop().character;

            int result = doOperation(a, b, expression[i++]);
            stack.push(result + '0', 0);
        }
        else
        {
            ++i;
        }
    }

    return std::to_string(stack.pop().character - '0');
}