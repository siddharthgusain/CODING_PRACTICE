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
    stack<int> vstack;
    stack<string> infix;
    stack<string> postfix;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];

        if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
        {
            stringstream ss;
            string s;
            ss << ch;
            ss >> s;

            int v1 = vstack.top();
            vstack.pop();
            int v2 = vstack.top();
            vstack.pop();
            int val = operation(v1, v2, ch);
            vstack.push(val);

            string inv1 = infix.top();
            infix.pop();
            string inv2 = infix.top();
            infix.pop();
            string inv = "(" + inv1 + s + inv2 + ")";
            infix.push(inv);

            string postv1 = postfix.top();
            postfix.pop();
            string postv2 = postfix.top();
            postfix.pop();
            string postv = postv1 + postv2 + s;
            postfix.push(postv);
        }
        else
        {
            vstack.push(ch - '0');
            stringstream ss;
            string s;
            ss << ch;
            ss >> s;
            infix.push(s);
            postfix.push(s);
        }
    }
    cout << vstack.top() << endl;
    vstack.pop();
    cout << infix.top() << endl;
    vstack.pop();
    cout << postfix.top() << endl;
    vstack.pop();
}

/*
Question :- https://nados.io/question/prefix-evaluation-and-conversions
Article:-https://nados.io/article/prefix-evaluation-and-conversion
Video:- https://www.youtube.com/watch?v=Q-Nw-dTApjk
*/