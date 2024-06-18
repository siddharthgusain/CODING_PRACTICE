#include <iostream>
#include <vector>
using namespace std;

int allowed_jumps[] = {1, 2, 3};

std::vector<string> get_staircase_path(int num_of_stairs)
{

    if (num_of_stairs < 0)
        return {};

    if (num_of_stairs == 0)
        return {""};

    vector<string> path1 = get_staircase_path(num_of_stairs - allowed_jumps[0]);
    vector<string> path2 = get_staircase_path(num_of_stairs - allowed_jumps[1]);
    vector<string> path3 = get_staircase_path(num_of_stairs - allowed_jumps[2]);

    vector<string> all_paths;
    char str1 = (allowed_jumps[0] + '0');
    char str2 = (allowed_jumps[1] + '0');
    char str3 = (allowed_jumps[2] + '0');

    for (string ele : path1)
        all_paths.push_back(str1 + ele);

    for (string ele : path2)
        all_paths.push_back(str2 + ele);

    for (string ele : path3)
        all_paths.push_back(str3 + ele);

    return all_paths;
}

int main()
{
    int num_of_stairs;
    cin >> num_of_stairs;

    vector<string> result = get_staircase_path(num_of_stairs);

    for (auto path : result)
    {
        cout << path << endl;
    }

    return 0;
}