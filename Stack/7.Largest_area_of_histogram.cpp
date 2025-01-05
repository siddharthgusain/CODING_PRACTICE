#include <iostream>
#include <vector>
#include <stack>

int largestRectangleArea(const std::vector<int> &heights)
{
    std::stack<int> stk; // Stack to store indices of the bars
    int max_area = 0;    // Variable to store the maximum area
    int n = heights.size();

    for (int i = 0; i < n; i++)
    {
        // Maintain the stack in increasing order of heights
        while (!stk.empty() && heights[i] < heights[stk.top()])
        {
            int height = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            max_area = std::max(max_area, height * width);
        }
        stk.push(i);
    }

    // Calculate area for remaining bars in stack
    while (!stk.empty())
    {
        int height = heights[stk.top()];
        stk.pop();
        int width = stk.empty() ? n : n - stk.top() - 1;
        max_area = std::max(max_area, height * width);
    }

    return max_area;
}

int main()
{
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << std::endl;
    return 0;
}
