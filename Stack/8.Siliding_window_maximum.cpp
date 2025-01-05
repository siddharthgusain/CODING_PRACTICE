#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k)
{
    std::deque<int> dq; // Deque to store indices of elements
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // Remove indices that are out of the window
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // Add the maximum element of the window to the result
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// Main function to test the code
int main()
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = maxSlidingWindow(nums, k);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
