#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{
    if (intervals.empty())
        return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Use a stack to merge intervals
    stack<pair<int, int>> s;
    s.push(intervals[0]);

    for (size_t i = 1; i < intervals.size(); i++)
    {
        // Get the interval at the top of the stack
        auto top = s.top();

        // Check if the current interval overlaps with the top interval
        if (top.second >= intervals[i].first)
        {
            // Merge intervals by updating the end of the top interval
            s.pop();
            s.push({top.first, max(top.second, intervals[i].second)});
        }
        else
        {
            // No overlap, push the current interval onto the stack
            s.push(intervals[i]);
        }
    }

    // Step 3: Transfer stack contents to the result
    vector<pair<int, int>> merged;
    while (!s.empty())
    {
        merged.push_back(s.top());
        s.pop();
    }

    // Reverse the result as the stack produces intervals in reverse order
    reverse(merged.begin(), merged.end());

    return merged;
}

int main()
{
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Merge overlapping intervals
    vector<pair<int, int>> merged = mergeIntervals(intervals);

    // Print merged intervals
    cout << "Merged Intervals: ";
    for (const auto &interval : merged)
    {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }

    return 0;
}
