#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    stack<int> st;

    vector<int> next_greater_element(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    // for last element
    st.push(vec[n - 1]);
    next_greater_element[n - 1] = -1;

    // remaining element
    for (int i = n - 2; i >= 0; i--)
    {
        int element = vec[i];
        while (st.size() > 0 && element >= st.top()) // pop till all the smaller elements are removed
            st.pop();

        if (st.size() == 0) // if stacks becomes empty after popping then NGE is -1
            next_greater_element[i] = -1;
        else
            next_greater_element[i] = st.top(); // otherwise the element at top is NGE

        st.push(element); // push the current element being processes to stack
    }

    for (int ele : next_greater_element)
        cout << ele << ",";

    return 0;
}

// First approach could be with two loops --> O(n^2) , space :- O(1)
// Second approach could be sorting the array and traversing --> O(nlogn),O(1)
// with stack :- time :- O(n) space O(n)

/*
Question :-https://nados.io/question/next-greater-element-to-the-right
Article:- https://nados.io/article/next-greater-element-to-the-right
Video:- https://www.youtube.com/watch?v=rSf9vPtKcmI
*/
