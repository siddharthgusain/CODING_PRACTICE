#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void sliding_window(vector<int> &arr, int k, int size)
{
    int n = size;
    vector<int> ngr(n);

    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = arr[i];
        while (!st.empty() && ele >= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ngr[i] = n;
        }
        else
        {
            ngr[i] = st.top();
        }
        st.push(i);
    }

    vector<int> ans((n - k + 1), 0);
    int pc = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (pc < i)
        {
            pc = i;
        }
        int ep = i + k; // _----_ > Ending Point
        while (ep > ngr[pc])
        {
            pc = ngr[pc];
        }

        ans[i] = arr[pc];
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int size = arr.size();

    sliding_window(arr, k, size);
    return 0;
}

// can be solved with normal interation but complexity will be O(n^2)
// This algorithm can be used in operating system for TCP sliding window and cache replacement as well

/*
Question :-https://nados.io/question/sliding-window-maximum
Article:- https://nados.io/article/sliding-window-maximum
Video:- https://www.youtube.com/watch?v=tCVOQX3lWeI
*/