#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr)
{
    cout << "Printing array:" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(vector<int> &vec, int i, int j)
{
    std::cout << "Swapping:" << vec[i] << "," << vec[j] << std::endl;
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void partition_array(vector<int> &vec, int pivot)
{
    if (vec.size() == 0)
        return;

    int i = 0;
    int j = 0;

    while (i < vec.size())
    {
        if (vec[i] > pivot)
        {
            i++; // i checks whether the value is bigger than pivot , so it "i" makes sure that it has seen something greater than pivot
            // "j" is still pointing to a larger element than pivot because it will be usefull for swapping when i is pointing to smaller element than pivot
        }
        else if (vec[i] <= pivot) // if i find some element smaller element
        {
            swap(vec, i, j);
            i++; // i work is done for this element
            j++; // j is sure that to its left we have smaller element than pivot, so j is only moved when swapping is done
        }
    }
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

    int pivot;
    cin >> pivot;
    print(vec);
    cout << "pivot=" << pivot << endl;

    partition_array(vec, pivot);

    print(vec);
    return 0;
}

/*
Time comp:- o(n)
Space comp:- o(1)
*/

/*
Question :-https://nados.io/question/partition-an-array
Article:- https://nados.io/article/partition-an-array
Video:- https://www.youtube.com/watch?v=if40LxQ8_Xo
*/