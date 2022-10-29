#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> merge_sorted_arrays(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> merge_sort(vector<int> &arr, int si, int ei)
{
    if (si == ei)
    {
        vector<int> base;
        base.push_back(arr[si]);
        return base;
    }

    int mid = (si + ei) / 2;
    vector<int> A = merge_sort(arr, si, mid);
    vector<int> B = merge_sort(arr, mid + 1, ei);

    return merge_sorted_arrays(A, B);
}

vector<int> merge_sort(vector<int> &arr)
{
    return merge_sort(arr, 0, arr.size() - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    vector<int> ans = merge_sort(A);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}

/*
Time comp:- o(nlogn)
Space comp:- o(n)
*/

/*
Question :-https://nados.io/question/merge-sort
Article:- https://nados.io/article/merge-sort
Video:- https://www.youtube.com/watch?v=aiUHB-3EOg8
*/