// Last updated: 10/5/2025, 9:02:47 AM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
        
    }
};