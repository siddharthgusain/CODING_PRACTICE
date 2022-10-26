#include <bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{
    if (sos > tar)
    {
        return;
    }

    if (idx == arr.size())
    {
        if (sos == tar)
        {
            cout << set << "." << endl;
        }
        return;
    }

    string val = to_string(arr[idx]);

    printTargetSumSubsets(arr, idx + 1, set + val + ", ", sos + arr[idx], tar); // adding the current element
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);                         // not addding current element
}

int main()
{
    int n, tar;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> tar;
    printTargetSumSubsets(arr, 0, "", 0, tar);
}

/*
Question :- https://nados.io/question/target-sum-subsets
Article:- https://nados.io/article/target-sum-subsets
Video:- https://www.youtube.com/watch?v=HGDmj5NrrjM
*/
