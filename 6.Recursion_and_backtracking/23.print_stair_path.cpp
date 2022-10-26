#include <iostream>
using namespace std;

void printStairPaths(int n, string path)
{
    if (n <= 0)
    {
        if (n == 0)
        {
            cout << path << endl;
        }
        return;
    }

    printStairPaths(n - 1, path + "1");
    printStairPaths(n - 2, path + "2");
    printStairPaths(n - 3, path + "3");
}

int main()
{

    int n;
    cin >> n;

    printStairPaths(n, "");
}

/*
Question :- https://nados.io/question/print-stair-paths
Article:- https://nados.io/article/print-stair-paths
Video:- https://www.youtube.com/watch?v=NEuYcztalew
*/