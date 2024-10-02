#include <bits/stdc++.h>
using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void targetSumPair(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end()); // This is important
    int si = 0, ei = arr.size() - 1;
    while (si < ei)
    {
        int sum = arr[si] + arr[ei];
        if (sum < target)
        {
            si++;
        }
        else if (sum > target)
        {
            ei--;
        }
        else
        {
            cout << arr[si] << ", " << arr[ei] << endl;
            si++;
            ei--;
        }
    }
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;
    targetSumPair(vec, target);
    return 0;
}

/*
Question :- https://nados.io/question/target-sum-pair-1
Article:- https://nados.io/article/target-sum-pair-1
Video:- https://www.youtube.com/watch?v=4t9jv9AkVdE
*/