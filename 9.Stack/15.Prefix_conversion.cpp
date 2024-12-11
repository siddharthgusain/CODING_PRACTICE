#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to evaluate the prefix expression
int evaluatePrefix(const string &expr)
{
    stack<int> s;
    for (int i = expr.length() - 1; i >= 0; i--)
    {
        char ch = expr[i];
        if (isOperator(ch))
        {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
        else
        {
            s.push(ch - '0'); // Assuming the operands are single digits
        }
    }
    return s.top();
}

// Function to convert Prefix to Infix
string prefixToInfix(const string &expr)
{
    stack<string> s;
    for (int i = expr.length() - 1; i >= 0; i--)
    {
        char ch = expr[i];
        if (isOperator(ch))
        {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string result = "(" + operand1 + ch + operand2 + ")";
            s.push(result);
        }
        else
        {
            s.push(string(1, ch)); // Push the operand
        }
    }
    return s.top();
}

// Function to convert Prefix to Postfix
string prefixToPostfix(const string &expr)
{
    stack<string> s;
    for (int i = expr.length() - 1; i >= 0; i--)
    {
        char ch = expr[i];
        if (isOperator(ch))
        {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string result = operand1 + operand2 + ch;
            s.push(result);
        }
        else
        {
            s.push(string(1, ch)); // Push the operand
        }
    }
    return s.top();
}

int main()
{
    string expr;
    cout << "Enter a prefix expression: ";
    cin >> expr;

    // Evaluate the Prefix expression
    int result = evaluatePrefix(expr);
    cout << "Prefix Expression Evaluation: " << result << endl;

    // Convert Prefix to Infix
    string infix = prefixToInfix(expr);
    cout << "Prefix to Infix: " << infix << endl;

    // Convert Prefix to Postfix
    string postfix = prefixToPostfix(expr);
    cout << "Prefix to Postfix: " << postfix << endl;

    return 0;
}
