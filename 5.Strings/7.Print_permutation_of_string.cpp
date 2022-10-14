#include <iostream>
#include <string>
using namespace std;

int factorial(string str)
{
    int n = str.length();
    int count = 1;
    for (int i = n; i >= 1; i--)
    {

        count *= i;
    }

    return count;
}
void printallperm(string str)
{
    int limit = factorial(str);
    int k = 0;
    while (k < limit)
    {
        int temp = k;
        string ans = str;

        for (int i = str.length(); i >= 1; i--)
        {
            int rem = temp % i;
            temp = temp / i;
            cout << ans[rem];
            ans.erase(rem, 1);
        }
        cout << endl;
        k++;
    }
}

int main()
{
    string str;
    getline(cin, str);

    printallperm(str);
}

/*
Question :-https://nados.io/question/print-all-permutations-of-a-string-iteratively
Article :- https://nados.io/article/string-with-difference-of-every-two-consecutive-characters-in-java
Video:- https://www.youtube.com/watch?v=PHtNm0B9Ig4
*/