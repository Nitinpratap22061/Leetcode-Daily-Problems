// Last updated: 10/5/2025, 9:02:24 AM
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    int t[100001];
public:
    int solve(vector<int> &nums, int n, int idx) {
        if (idx >= n - 1) {
            return 0;
        }
        if(t[idx]!=-1)
          {
              return t[idx];
          }
        
        // if (nums[idx] == 0) {
        //     return INT_MAX;
        // }
        
        int mini = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            long long ans = 1LL + solve(nums, n, idx + i);
            mini = min(static_cast<long long>(mini), ans);
        }
        
        return t[idx]=mini;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, n, 0) == INT_MAX ? 0 : solve(nums, n, 0);
    }
};
