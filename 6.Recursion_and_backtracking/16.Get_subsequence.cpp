#include <iostream>
#include <vector>
using namespace std;

vector<string> get_subsequence(string str)
{
    if (str.size() == 0)
        return {""};

    string c = str.substr(0, 1);
    string sub_string = str.substr(1, str.size());

    vector<string> ret = get_subsequence(sub_string);
    vector<string> output;
    for (auto i : ret)
    {
        output.push_back("_ " + i);
        output.push_back(c + " " + i);
    }
    return output;
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

/*
Question :- https://nados.io/question/get-subsequence
Article:- https://nados.io/article/get-subsequence
Video:- https://www.youtube.com/watch?v=Sa5PmCFF_zI
*/