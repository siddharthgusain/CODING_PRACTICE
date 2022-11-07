#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

int precedance(char ch)
{
    if (ch == '*')
    {
        return 2;
    }
    else if (ch == '/')
    {
        return 2;
    }
    else if (ch == '+')
    {
        return 1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string str;
    getline(cin, str);

    stack<string> postFix;
    stack<string> preFix;
    stack<char> op;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);

        if (ch == '(')
        {
            op.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string s = string(1, ch);

            postFix.push(s);
            preFix.push(s);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (op.size() > 0 && op.top() != '(' && precedance(ch) <= precedance(op.top()))
            {
                char o = op.top();
                op.pop();
                string s = string(1, o);

                string postVal2 = postFix.top();
                postFix.pop();
                string postval1 = postFix.top();
                postFix.pop();

                postFix.push(postval1 + postVal2 + s);

                string preval2 = preFix.top();
                preFix.pop();
                string preval1 = preFix.top();
                preFix.pop();

                preFix.push(s + preval1 + preval2);
            }
            op.push(ch);
        }
        else if (ch == ')')
        {
            while (op.size() > 0 && op.top() != '(')
            {
                char o = op.top();
                op.pop();
                string s = string(1, o);

                string postVal2 = postFix.top();
                postFix.pop();
                string postval1 = postFix.top();
                postFix.pop();

                postFix.push(postval1 + postVal2 + s);

                string preval2 = preFix.top();
                preFix.pop();
                string preval1 = preFix.top();
                preFix.pop();

                preFix.push(s + preval1 + preval2);
            }
            op.pop();
        }
    }

    while (op.size() > 0)
    {
        char o = op.top();
        op.pop();
        string s = string(1, o);

        string postVal2 = postFix.top();
        postFix.pop();
        string postval1 = postFix.top();
        postFix.pop();

        postFix.push(postval1 + postVal2 + s);

        string preval2 = preFix.top();
        preFix.pop();
        string preval1 = preFix.top();
        preFix.pop();

        preFix.push(s + preval1 + preval2);
    }

    string post = postFix.top();
    string pre = preFix.top();

    cout << post << endl;
    cout << pre << endl;

    return 0;
}
/*
-> infix is human readable but , postfix and prefix is used by computers in making expression tree
that is used in compilers.
-> These algorithm is usefull in compiler design
*/

/*
Question :- https://nados.io/question/infix-conversions
Article:- https://nados.io/article/infix-conversions
Video:- https://www.youtube.com/watch?v=Nfui0rgbQe8
*/