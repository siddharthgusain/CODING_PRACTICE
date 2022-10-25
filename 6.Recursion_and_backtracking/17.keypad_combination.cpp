#include <iostream>
#include <vector>
using namespace std;

string keypad_map[10] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> get_keypad_comb(string str)
{
    if (str.size() == 0)
        return {""};

    string current_char = str.substr(0, 1);
    int number_pressed = current_char.at(0) - '0';
    string remaining_substr = str.substr(1, str.size());

    vector<string> sub_problem = get_keypad_comb(remaining_substr);

    string map_string = keypad_map[number_pressed];
    vector<string> result;

    for (int i = 0; i < map_string.size(); i++)
    {
        char c = map_string.at(i);
        for (string ele : sub_problem)
            result.push_back(c + ele);
    }

    return result;
}

int main()
{
    string keypad_string;
    cin >> keypad_string;

    vector<string> result = get_keypad_comb(keypad_string);

    cout << "[";
    for (string ele : result)
        cout << ele << ",";
    cout << "]";

    return 0;
}

/*
Question :- https://nados.io/question/get-kpc
Article:-https://nados.io/article/get-kpc
Video:- https://www.youtube.com/watch?v=3fjt19bjs3A
*/