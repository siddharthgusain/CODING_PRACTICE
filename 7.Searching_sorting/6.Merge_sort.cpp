#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> merge_arrays(std::vector<int> &vec1, std::vector<int> &vec2)
{

    if (vec1.size() == 0 || vec2.size() == 0)
        return vec1.size() == 0 ? vec2 : vec1;

    vector<int> output(vec1.size() + vec2.size(), 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("Left array -> ");
    print(vec1);
    cout << ("Right array -> ");
    print(vec2);

    int i = 0, j = 0, k = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] <= vec2[j])
        {
            output[k] = vec1[i];
            i++;
            k++;
        }
        else
        {
            output[k] = vec2[j];
            j++;
            k++;
        }
    }

    while (i < vec1.size()) // if i is not at the end of first array
    {
        output[k] = vec1[i];
        k++;
        i++;
    }

    while (j < vec2.size()) // if j is not at the end of second array
    {
        output[k] = vec2[j];
        j++;
        k++;
    }

    return output;
}

vector<int> merge_sort(vector<int> &vec, int low, int high)
{
    if (low == high)
    {
        vector<int> base_case;
        base_case.push_back(vec[low]);
        return base_case;
    }

    int mid = (low + high) / 2;
    vector<int> first_half = merge_sort(vec, low, mid);                     // left array
    vector<int> second_half = merge_sort(vec, mid + 1, high);               // right array
    vector<int> final_sorted_array = merge_arrays(first_half, second_half); // merge sorted array

    return final_sorted_array;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<int> sorted_array = merge_sort(vec, 0, vec.size() - 1);

    for (int ele : sorted_array)
        std::cout << ele << ",";

    return 0;
}