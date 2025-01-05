#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    std::stack<int> stk;
    std::vector<int> result(nums.size(), -1);

    for (int i = nums.size() - 1; i >= 0; i--) // Starting from Right 
    {
        // Pop elements smaller than the current element
        while (!stk.empty() && stk.top() <= nums[i])
        {
            stk.pop();
        }

        // If the stack is not empty, the top element is the next greater element
        if (!stk.empty())
        {
            result[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(nums[i]);
    }

    return result;
}

int main()
{
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> result = nextGreaterElement(nums);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
