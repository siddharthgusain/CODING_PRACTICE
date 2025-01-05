#include <iostream>
#include <vector>
using namespace std;

vector<string> get_subsequence(string str)
{
    if (str.size() == 0)
        return {""};

    string c = str.substr(0, 1);
    string sub_string = str.substr(1, str.size());

    vector<string> partial_result = get_subsequence(sub_string);
    vector<string> final_result;
    for (auto i : partial_result)
    {
        final_result.push_back("_ " + i);
        final_result.push_back(c + " " + i);
    }
    return final_result;
}

int main()
{
    string str;
    cin >> str;

    vector<std::string> subsequence_vector = get_subsequence(str);

    for (string ele : subsequence_vector)
        cout << ele << endl;

    return 0;
}