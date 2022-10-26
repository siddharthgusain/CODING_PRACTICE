#include <iostream>
using namespace std;

void printPermutations(string str, string asf)
{
    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string ros = str.substr(0, i) + str.substr(i + 1);
        printPermutations(ros, asf + ch);
    }
}

int main()
{
    string str;
    cin >> str;

    printPermutations(str, "");
}

/*
Question :- https://nados.io/question/print-permutations
Article:- https://nados.io/article/print-permutations
Video:- https://www.youtube.com/watch?v=sPAT_DbvDj0
*/
