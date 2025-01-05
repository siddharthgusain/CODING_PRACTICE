

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
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &arr)
{
    int n = arr.size();
    int pt1 = 0, itr = 0, pt2 = n - 1;
    while (itr <= pt2)
    {
        if (arr[itr] == 0)
        {
            itr++;
            pt1++;
            swap(arr, itr++, pt1++);
        }
        else if (arr[itr] == 2)
        {
            pt2--;
            swap(arr, itr, pt2);
        }
        else
            itr++;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012(A);
    print(A);
    return 0;
}

/*
Question :- https://nados.io/question/sort-012
Article:- https://nados.io/article/sort-012
Video:- https://www.youtube.com/watch?v=MbV26HWqxrs
*/