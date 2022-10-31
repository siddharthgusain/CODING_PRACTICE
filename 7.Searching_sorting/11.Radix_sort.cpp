#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void display(vector<int> &arr)
{
  for (int ele : arr)
  {
    cout << ele << " ";
  }
}

void count_sort(vector<int> &arr, int d)
{
  int fsize = 10;
  vector<int> freq(fsize, 0);

  for (int i = 0; i < arr.size(); i++)
  {
    int idx = (arr[i] / d) % 10;
    freq[idx]++;
  }

  for (int i = 1; i < freq.size(); i++)
  {
    freq[i] = freq[i] + freq[i - 1];
  }

  vector<int> ans(arr.size(), 0);

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    int idx = (arr[i] / d) % 10;
    ans[freq[idx] - 1] = arr[i];
    freq[idx]--;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    arr[i] = ans[i];
  }

  cout << "After sorting on " << d << " place -> ";
  display(arr);
  cout << endl;
}

void radix_Sort(vector<int> &arr)
{
  // write your code here
  int maxVal = INT_MIN;
  for (int ele : arr)
  {
    maxVal = max(maxVal, ele);
  }

  int exp = 1;
  while (exp <= maxVal)
  {
    count_sort(arr, exp);
    exp *= 10;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  radix_Sort(arr);
  display(arr);
  return 0;
}

/*
Question :- https://nados.io/question/count-sort
Article:- https://nados.io/article/count-sort
Video:- https://www.youtube.com/watch?v=a5e7RgCdel0
*/