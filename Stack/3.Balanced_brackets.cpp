#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string &expression)
{
    std::stack<char> stk;

    // Traverse each character in the expression
    for (char ch : expression)
    {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        // Check for matching closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stk.empty())
            {
                // No corresponding opening bracket
                return false;
            }
            char top = stk.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                stk.pop(); // Pop matching opening bracket
            }
            else
            {
                return false; // Mismatched brackets
            }
        }
        // Ignore any non-bracket characters
    }

    // Check if stack is empty after processing
    return stk.empty();
}

// Main function to test the function
int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (isBalanced(expression))
    {
        std::cout << "The expression has balanced brackets.\n";
    }
    else
    {
        std::cout << "The expression does not have balanced brackets.\n";
    }

    return 0;
}
