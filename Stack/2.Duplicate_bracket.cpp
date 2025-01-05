#include <iostream>
#include <stack>
#include <string>

bool hasDuplicateBrackets(const std::string &expression)
{
    std::stack<char> stk;

    for (char ch : expression)
    {
        if (ch == ')')
        {
            if (!stk.empty() && stk.top() == '(')
            {
                // Duplicate brackets found
                return true;
            }
            else
            {
                // Pop until an opening bracket is found
                while (!stk.empty() && stk.top() != '(')
                {
                    stk.pop();
                }
                if (!stk.empty())
                {
                    stk.pop(); // Remove the opening bracket '('
                }
            }
        }
        else
        {
            // Push every character other than closing bracket ')'
            stk.push(ch);
        }
    }

    return false; // No duplicate brackets found
}

// Main function to test the function
int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    if (hasDuplicateBrackets(expression))
    {
        std::cout << "The expression has duplicate brackets.\n";
    }
    else
    {
        std::cout << "The expression does not have duplicate brackets.\n";
    }

    return 0;
}
