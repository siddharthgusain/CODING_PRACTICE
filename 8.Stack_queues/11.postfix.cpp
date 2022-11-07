#include <bits/stdc++.h>

using namespace std;

int operation(int v1, int v2, char op)
{
    if (op == '+')
    {
        return v1 + v2;
    }
    else if (op == '-')
    {
        return v1 - v2;
    }
    else if (op == '*')
    {
        return v1 * v2;
    }
    else if (op == '/')
    {
        return v1 / v2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string exp;
    cin >> exp;

    stack<int> vs;
    stack<string> is;
    stack<string> ps;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
        {
            string s = string(1, ch);

            int v2 = vs.top();
            vs.pop();
            int v1 = vs.top();
            vs.pop();
            int val = operation(v1, v2, ch);
            vs.push(val);

            string inv2 = is.top();
            is.pop();
            string inv1 = is.top();
            is.pop();
            string inv = "(" + inv1 + s + inv2 + ")";
            is.push(inv);

            string postv2 = ps.top();
            ps.pop();
            string postv1 = ps.top();
            ps.pop();
            string postv = s + postv1 + postv2;
            ps.push(postv);
        }
        else
        {
            vs.push(ch - '0');
            string s = string(1, ch);
            is.push(s);
            ps.push(s);
        }
    }
    cout << vs.top() << endl;
    vs.pop();
    cout << is.top() << endl;
    is.pop();
    cout << ps.top() << endl;
    ps.pop();

    return 0;
}

/*
Question :- https://nados.io/question/postfix-evaluation-and-conversions
Article:-https://nados.io/article/postfix-evaluation-and-conversion
Video:- https://www.youtube.com/watch?v=BlNXOtll7jo
*/