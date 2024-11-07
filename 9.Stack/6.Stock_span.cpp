#include <iostream>
#include <vector>
#include <stack>

std::vector<int> calculateSpan(const std::vector<int> &prices)
{
    std::vector<int> span(prices.size());
    std::stack<int> stk; // Stack to store indices

    for (int i = 0; i < prices.size(); i++)
    {
        // Pop elements from the stack while current price is greater than or equal
        while (!stk.empty() && prices[i] >= prices[stk.top()])
        {
            stk.pop();
        }

        // Calculate span
        if (stk.empty())
        {
            span[i] = i + 1; // No previous higher price
        }
        else
        {
            span[i] = i - stk.top();
        }

        // Push current day's index onto the stack
        stk.push(i);
    }

    return span;
}

// Main function to test the code
int main()
{
    std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    std::vector<int> result = calculateSpan(prices);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
