// Last updated: 10/5/2025, 8:53:54 AM
#include <vector>
#include <numeric> // For accumulate
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxCount = 0;
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ans.push_back(nums[i]);
            } else {
                int sum = accumulate(begin(ans), end(ans), 0);
                maxCount = max(maxCount, sum);
                ans.clear();
                ans.push_back(nums[i]);
            }
        }

        
        int sum = accumulate(begin(ans), end(ans), 0);
        maxCount = max(maxCount, sum);

        return maxCount;
    }
};
