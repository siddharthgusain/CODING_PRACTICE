#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    stack<int> st;

    vector<int> span(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    st.push(0); // pushing index in array not the value
    span[0] = 1;

    for (int i = 1; i < vec.size(); i++)
    {
        int element = vec[i];
        while (st.size() > 0 && element >= vec[st.top()])
            st.pop();

        if (st.size() == 0)
            span[i] = i + 1;
        else
            span[i] = i - st.top();

        st.push(i);
    }

    for (int ele : span)
    {
        cout << ele << ",";
    }
    return 0;
}

// can be solved to next greater element approach with stack

/*
Question :-https://nados.io/question/stock-span
Article:- https://nados.io/article/stock-span
Video:- https://www.youtube.com/watch?v=0BsPlzqksZQ
*/