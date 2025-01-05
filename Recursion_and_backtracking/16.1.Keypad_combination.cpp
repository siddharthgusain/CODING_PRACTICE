#include <iostream>
#include <vector>
using namespace std;

string keypad_map[10] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> get_keypad_comb(string &keypad_str)
{
    if (keypad_str.size() == 0) // Smallest Problem ->Base case
        return {""};

    string current_character = keypad_str.substr(0, 1);
    int number_pressed = current_character.at(0) - '0'; // converting to index in array
    string remaining_str = keypad_str.substr(1);

    string map_string = keypad_map[number_pressed];                 // getting string combination for that index
    vector<string> partial_result = get_keypad_comb(remaining_str); // recursive call
    vector<string> final_result;

    for (int i = 0; i < map_string.size(); i++)
    {
        char c = map_string.at(i);
        for (string ele : partial_result)
            final_result.push_back(c + ele); // creating Final Strings and Pushing to result
    }

    return final_result;
}

int main()
{
    string keypad_string;
    cin >> keypad_string;

    vector<string> result = get_keypad_comb(keypad_string);
    for (auto ele : result)
    {
        std::cout << ele << " ";
    }

    return 0;
}