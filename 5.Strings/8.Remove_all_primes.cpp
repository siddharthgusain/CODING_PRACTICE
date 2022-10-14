#include <iostream>
#include <vector>
using namespace std;

bool isprime(int val)
{
    for (int j = 2; j * j <= val; j++)
    {
        if (val % j == 0)
        {
            return false;
        }
    }

    return true;
}

void removeprimes(vector<int> v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (isprime(v[i]))
        {
            v.erase(v.begin() + i);
        }
    }
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i];
        if (i < v.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    removeprimes(v);

    return 0;
}

/*
Question :- https://nados.io/question/remove-primes
Article :- https://www.pepcoding.com/resources/online-java-foundation/string,-string-builder-and-arraylist/remove_all_primes/topic
Video:- https://www.youtube.com/watch?v=jj90JZ_wLoo
*/