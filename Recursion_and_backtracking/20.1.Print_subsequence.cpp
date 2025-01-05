#include <iostream>
#include <vector>
using namespace std;

void print_subsequence(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string first_character = ques.substr(0, 1);
    string rest_string = ques.substr(1, ques.size());

    print_subsequence(rest_string, ans + "");              // CAll for : if character is not included
    print_subsequence(rest_string, ans + first_character); // Call for : if character is included
}

int main()
{
    string str;
    cin >> str;
    print_subsequence(str, "");
    return 0;
}