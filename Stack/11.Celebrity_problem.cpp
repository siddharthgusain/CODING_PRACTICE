#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findCelebrity(int N, vector<vector<int>> &M)
{
    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < N; i++)
    {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (M[A][B] == 1)
        {
            // A knows B, so A cannot be a celebrity, push B back
            s.push(B);
        }
        else
        {
            // A does not know B, so B cannot be a celebrity, push A back
            s.push(A);
        }
    }

    // The last person in the stack is a potential celebrity
    int candidate = s.top();

    // Step 3: Verify the candidate
    for (int i = 0; i < N; i++)
    {
        // candidate should not know anyone else, and everyone else should know candidate
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
        {
            return -1;
        }
    }

    return candidate;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {1, 1, 0}};
    int N = 3;
    int celebrity = findCelebrity(N, M);
    if (celebrity == -1)
        cout << "No celebrity found" << endl;
    else
        cout << "Celebrity is person " << celebrity << endl;
    return 0;
}
