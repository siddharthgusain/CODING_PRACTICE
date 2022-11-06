#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string expression;
    cin >> expression;
    stack<char> st;

    // logic to check duplicate bracket
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression.at(i);
        if (ch == ')') // if character is closing bracket
        {
            if (st.top() == '(') // if u get closing bracket right at the top that means no content was there in between
            {
                cout << "true";
                return 0;
            }
            else // if anything other than closing bracket was found, pop till you find opening bracket
            {
                while (st.top() != '(')
                    st.pop();

                st.pop(); // also pop the opening bracket
            }
        }
        else // if the character being scanned is not closing bracket
        {
            st.push(ch);
        }
    }

    cout << "false";
    return 0;
}

/*
Question :-https://nados.io/question/duplicate-brackets
Article:- https://nados.io/article/duplicate-brackets
Video:- https://www.youtube.com/watch?v=aMPXhEdpXFA
*/