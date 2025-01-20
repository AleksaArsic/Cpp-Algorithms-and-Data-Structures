#include <iostream>
#include <string_view>
#include <string>
#include <stack>

// Time complexity -> o(n)
// Space complexity -> o(n) -> we need additional stack of maximal size = str.size()
bool areParenthesisBalanced(std::string_view expression)
{
    std::stack<char> stack;

    for(unsigned int i = 0; i < expression.size(); ++i)
    {
        if(expression[i] == '(')
        {
            stack.push(expression[i]);
        }
        else if(expression[i] == ')')
        {
            if(stack.empty())
            {
                return false;
            }
            stack.pop();
        }
    }
    
    return stack.empty();
}

int main()
{
    std::string expression = "((a + b) * (c - d))";

    if(areParenthesisBalanced(expression))
    {
        std::cout << "In expression: " << expression << " parenthesis are balanced." << std::endl;
    }
    else
    {
        std::cout << "In expression: " << expression << " parenthesis are not balanced." << std::endl;
    }

    return 0;
}