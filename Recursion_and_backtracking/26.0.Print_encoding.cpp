#include <iostream>
#include <string>
using namespace std;

void print_encoding(string str, string asf)
{
    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }

    if (str[0] == '0')
    {
        return;
    }

    string s1 = str.substr(0, 1);
    string ros1 = str.substr(1);

    print_encoding(ros1, asf + (char)(stoi(s1) + 'a' - 1));

    if (str.length() >= 2)
    {
        string s2 = str.substr(0, 2);
        string ros2 = str.substr(2);
        if (stoi(s2) <= 26)
            print_encoding(ros2, asf + (char)(stoi(s2) + 'a' - 1));
    }
}

int main()
{
    string str;
    cin >> str;

    print_encoding(str, "");
}