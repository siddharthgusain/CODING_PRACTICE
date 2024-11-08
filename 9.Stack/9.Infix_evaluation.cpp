#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

// Function to define precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform an operation and return the result
int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    return 0;
}

// Function to evaluate an infix expression
int evaluateInfix(const std::string &expression)
{
    std::stack<int> operands;   // Stack to store operands (numbers)
    std::stack<char> operators; // Stack to store operators and parentheses

    for (size_t i = 0; i < expression.length(); i++)
    {
        // Skip whitespaces
        if (expression[i] == ' ')
            continue;

        // If the token is a number
        if (isdigit(expression[i]))
        {
            int value = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                value = (value * 10) + (expression[i] - '0'); // Build the number
                i++;
            }
            operands.push(value);
            i--; // Adjust for next iteration
        }

        // If the token is an opening parenthesis
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }

        // If the token is a closing parenthesis
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.pop(); // Pop the opening parenthesis '('
        }

        // If the token is an operator
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/')
        {
            // While the precedence of the current operator is less than or equal to the precedence
            // of the operator on top of the operator stack, apply the top operator.
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i]))
            {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]); // Push the current operator
        }
    }

    // Apply remaining operators in the stack
    while (!operators.empty())
    {
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(applyOperation(a, b, op));
    }

    // The result is the last remaining operand
    return operands.top();
}

int main()
{
    std::string expression = "3 + 5 * (2 - 8)";
    try
    {
        int result = evaluateInfix(expression);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
