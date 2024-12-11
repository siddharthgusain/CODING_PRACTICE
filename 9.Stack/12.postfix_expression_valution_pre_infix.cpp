#include <iostream>
#include <stack>
#include <string>
#include <cctype>

void evaluateAndConvertPostfix(const std::string &postfix)
{
    std::stack<int> valueStack;          // For evaluation
    std::stack<std::string> prefixStack; // For prefix conversion
    std::stack<std::string> infixStack;  // For infix conversion

    for (char token : postfix)
    {
        if (isspace(token))
            continue; // Ignore spaces

        // If the token is an operand (digit)
        if (isdigit(token))
        {
            valueStack.push(token - '0');            // Push the integer value onto value stack
            prefixStack.push(std::string(1, token)); // Push as a string
            infixStack.push(std::string(1, token));  // Push as a string
        }
        // If the token is an operator
        else
        {
            // Pop top two values for evaluation
            int operand2 = valueStack.top();
            valueStack.pop();
            int operand1 = valueStack.top();
            valueStack.pop();
            int result = 0;

            switch (token)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                throw std::invalid_argument("Invalid operator in expression");
            }
            valueStack.push(result);

            // Pop top two elements for prefix
            std::string prefixOperand2 = prefixStack.top();
            prefixStack.pop();
            std::string prefixOperand1 = prefixStack.top();
            prefixStack.pop();
            prefixStack.push(token + prefixOperand1 + prefixOperand2);

            // Pop top two elements for infix
            std::string infixOperand2 = infixStack.top();
            infixStack.pop();
            std::string infixOperand1 = infixStack.top();
            infixStack.pop();
            infixStack.push("(" + infixOperand1 + token + infixOperand2 + ")");
        }
    }

    // Final results
    int finalValue = valueStack.top();
    std::string finalPrefix = prefixStack.top();
    std::string finalInfix = infixStack.top();

    // Output results
    std::cout << "Postfix Expression: " << postfix << std::endl;
    std::cout << "Evaluated Value: " << finalValue << std::endl;
    std::cout << "Prefix Expression: " << finalPrefix << std::endl;
    std::cout << "Infix Expression: " << finalInfix << std::endl;
}

int main()
{
    std::string postfixExpression = "53+82-*";
    evaluateAndConvertPostfix(postfixExpression);
    return 0;
}
