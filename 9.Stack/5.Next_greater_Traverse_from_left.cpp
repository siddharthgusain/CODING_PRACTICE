#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    std::vector<int> result(nums.size(), -1); // Initialize result with -1
    std::stack<int> stk;                      // Stack to store indices

    for (int i = 0; i < nums.size(); i++) // Traverse from Left
    {
        // Check if the current element is greater than the element at the stack's top index
        while (!stk.empty() && nums[i] > nums[stk.top()])
        {
            int index = stk.top();
            stk.pop();
            result[index] = nums[i]; // Set the next greater element
        }
        // Push the current index onto the stack
        stk.push(i);
    }

    return result;
}

// Main function to test the code
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
