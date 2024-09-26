#include <bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void print_target_sum_subsets(vector<int> arr, int idx, string set, int sos, int tar)
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

    print_target_sum_subsets(arr, idx + 1, set + val + ", ", sos + arr[idx], tar); // adding the current element
    print_target_sum_subsets(arr, idx + 1, set, sos, tar);                         // not adding current element
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
    print_target_sum_subsets(arr, 0, "", 0, tar);
}