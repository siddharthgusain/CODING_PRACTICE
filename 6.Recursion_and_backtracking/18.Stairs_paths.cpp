#include <iostream>
#include <vector>
using namespace std;

vector<string> get_paths(int num)
{
    if (num < 0)
        return {};

    if (num == 0)
        return {""};

    vector<string> path1 = get_paths(num - 1);
    vector<string> path2 = get_paths(num - 2);
    vector<string> path3 = get_paths(num - 3);

    vector<string> output;

    for (string ele : path1)
        output.push_back("1" + ele);

    for (string ele : path2)
        output.push_back("2" + ele);

    for (string ele : path3)
        output.push_back("3" + ele);

    return output;
}

int main()
{
    int num_of_stairs;
    std::cin >> num_of_stairs;

    vector<string> result = get_paths(num_of_stairs);

    for (string ele : result)
        cout << ele << ",";
    return 0;
}

/*
Question :- https://nados.io/question/get-stair-paths
Article:- https://nados.io/article/get-stair-paths
Video:- https://www.youtube.com/watch?v=hMJAlbJIS7E
*/