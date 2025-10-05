// Last updated: 10/5/2025, 8:56:54 AM
#include <vector>
#include <stack>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> stack;

        // Monotonic decreasing stack
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[i] < nums[stack.top()]) {
                stack.push(i);
            }
        }

        int maxWidth = 0;

        // Iterate from the end to find the maximum width ramp
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && nums[i] >= nums[stack.top()]) {
                maxWidth = std::max(maxWidth, i - stack.top());
                stack.pop();
            }
        }

        return maxWidth;
    }
};
