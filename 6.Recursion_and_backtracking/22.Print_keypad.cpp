#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void print_keypad_comb(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string rest = ques.substr(1);

    for (char chcode : codes[ch - 48])
    {
        print_keypad_comb(rest, ans + chcode);
    }
}

int main()
{
    string str;
    cin >> str;
    print_keypad_comb(str, "");
}

/*
Question :- https://nados.io/question/print-kpc
Article:- https://nados.io/article/print-kpc
Video:- https://www.youtube.com/watch?v=4yMtvToiJE0
*/