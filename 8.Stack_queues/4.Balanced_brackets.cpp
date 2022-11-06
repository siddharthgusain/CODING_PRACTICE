#include <iostream>
#include <stack>
using namespace std;

bool handle_closing(stack<char> &st, char ch)
{
    if (st.size() == 0) // stack empty but string is having closing bracket
    {
        return false;
    }
    else if (st.top() != ch) // stack top has mismatching opening bracket
    {
        return false;
    }
    else // everythings fine , just pop()
    {
        st.pop();
        return true;
    }
}

int main()
{
    string expression;
    cin >> expression;
    stack<char> st;

    // logic to check balanced bracket
    // Tip:- dont push any charater other than brackets
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression.at(i);
        if (ch == '(' || ch == '{' || ch == '[') // if encounter opening brackets
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool result = handle_closing(st, '(');
            if (result == false)
            {
                cout << "Not balanced";
                return 0;
            }
        }
        else if (ch == '}')
        {
            bool result = handle_closing(st, '{');
            if (result == false)
            {
                cout << "Not balanced";
                return 0;
            }
        }
        else if (ch == ']')
        {
            bool result = handle_closing(st, '[');
            if (result == false)
            {
                cout << "Not balanced";
                return 0;
            }
        }
    }

    if (st.size() == 0) // After the whole iteration , something left on stack , so not balanced
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}

/*
Question :-https://nados.io/question/balanced-brackets
Article:- https://nados.io/article/balanced-brackets
Video:- https://www.youtube.com/watch?v=uuE2pEjLiEI
*/

// BONUS
// These kind of algorithm is used in compiler softwares to match syntax and expression