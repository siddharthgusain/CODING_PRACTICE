#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

// Function to define precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to apply an operator on two operands and return a new expression
std::string applyOperation(const std::string &a, const std::string &b, char op, bool isPrefix)
{
    if (isPrefix)
    {
        return op + a + b; // Prefix order: operator first
    }
    else
    {
        return a + b + op; // Postfix order: operator last
    }
}

// Function to convert infix expression to both prefix and postfix
void infixToPrefixPostfix(const std::string &expression, std::string &prefix, std::string &postfix)
{
    std::stack<char> operators;
    std::stack<std::string> prefixOperands;
    std::stack<std::string> postfixOperands;

    for (char token : expression)
    {
        // If the token is an operand, push it to both operand stacks
        if (isalnum(token))
        {
            prefixOperands.push(std::string(1, token));
            postfixOperands.push(std::string(1, token));
        }
        // If the token is an opening parenthesis, push it to the operator stack
        else if (token == '(')
        {
            operators.push(token);
        }
        // If the token is a closing parenthesis
        else if (token == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                char op = operators.top();
                operators.pop();

                // Pop two operands from each stack and apply the operator
                std::string postB = postfixOperands.top();
                postfixOperands.pop();
                std::string postA = postfixOperands.top();
                postfixOperands.pop();
                postfixOperands.push(applyOperation(postA, postB, op, false));

                std::string preB = prefixOperands.top();
                prefixOperands.pop();
                std::string preA = prefixOperands.top();
                prefixOperands.pop();
                prefixOperands.push(applyOperation(preA, preB, op, true));
            }
            operators.pop(); // Discard the '('
        }
        // If the token is an operator
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            // Pop operators from the stack with higher or equal precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(token))
            {
                char op = operators.top();
                operators.pop();

                // Pop two operands from each stack and apply the operator
                std::string postB = postfixOperands.top();
                postfixOperands.pop();
                std::string postA = postfixOperands.top();
                postfixOperands.pop();
                postfixOperands.push(applyOperation(postA, postB, op, false));

                std::string preB = prefixOperands.top();
                prefixOperands.pop();
                std::string preA = prefixOperands.top();
                prefixOperands.pop();
                prefixOperands.push(applyOperation(preA, preB, op, true));
            }
            // Push the current operator onto the stack
            operators.push(token);
        }
    }

    // Apply any remaining operators in the stack
    while (!operators.empty())
    {
        char op = operators.top();
        operators.pop();

        // Pop two operands from each stack and apply the operator
        std::string postB = postfixOperands.top();
        postfixOperands.pop();
        std::string postA = postfixOperands.top();
        postfixOperands.pop();
        postfixOperands.push(applyOperation(postA, postB, op, false));

        std::string preB = prefixOperands.top();
        prefixOperands.pop();
        std::string preA = prefixOperands.top();
        prefixOperands.pop();
        prefixOperands.push(applyOperation(preA, preB, op, true));
    }

    // The final results in the stacks are our prefix and postfix expressions
    prefix = prefixOperands.top();
    postfix = postfixOperands.top();
}

int main()
{
    std::string expression = "(A-B/C)*(A/K-L)";
    std::string prefix, postfix;

    infixToPrefixPostfix(expression, prefix, postfix);

    std::cout << "Prefix: " << prefix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;

    return 0;
}
