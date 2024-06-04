#include <bits/stdc++.h>
using namespace std;

vector<int> next_smaller_Left(vector<int> arr)
{
    int n = arr.size();
    vector<int> nsl(n, 0);
    stack<int> st;
    nsl[0] = -1;
    st.push(0);
    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = st.top();
        }
        st.push(i);
    }
    return nsl;
}

vector<int> next_smaller_right(vector<int> arr)
{
    int n = arr.size();
    vector<int> nsr(n, 0);
    stack<int> st;
    nsr[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            nsr[i] = n;
        }
        else
        {
            nsr[i] = st.top();
        }
        st.push(i);
    }
    return nsr;
}

int largest_area_histogram(vector<int> arr)
{
    vector<int> nsl = next_smaller_Left(arr);  // next smaller to the left
    vector<int> nsr = next_smaller_right(arr); // next smaller to the right
    int max = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = arr[i] * (nsr[i] - nsl[i] - 1);
        if (ans > max)
        {
            max = ans;
        }
    }
    return max; // max of area
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = largest_area_histogram(arr);
    cout << ans;
    return 0;
}

// can be solved to next "smaller" element to left and next "smaller" element to right approach with stack
// This algorithm Can be used in data visualization
// very good solution with O(n) complexity

/*
Question :-https://nados.io/question/stock-span
Article:- https://nados.io/article/stock-span
Video:- https://www.youtube.com/watch?v=0BsPlzqksZQ
*/