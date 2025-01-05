#include <iostream>
#include <stack>
#include <string>
using namespace std;

string smallestNumberFollowingPattern(const string &pattern)
{
    stack<int> s;
    string result = "";

    int num = 1; // Start with the smallest number

    for (char ch : pattern)
    {
        // Push the current number onto the stack
        s.push(num++);

        // If the pattern is 'I', process the stack
        if (ch == 'I')
        {
            while (!s.empty())
            {
                result += to_string(s.top());
                s.pop();
            }
        }
    }

    // Push the last number
    s.push(num);

    // Pop any remaining numbers in the stack
    while (!s.empty())
    {
        result += to_string(s.top());
        s.pop();
    }

    return result;
}

int main()
{
    string pattern;
    cout << "Enter the pattern (I for increasing, D for decreasing): ";
    cin >> pattern;

    string result = smallestNumberFollowingPattern(pattern);
    cout << "Smallest number following the pattern is: " << result << endl;

    return 0;
}
