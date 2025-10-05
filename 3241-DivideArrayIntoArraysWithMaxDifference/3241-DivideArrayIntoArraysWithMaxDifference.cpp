// Last updated: 10/5/2025, 8:50:37 AM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans1;

        for (int i = 0; i < n; i++) {
            ans1.push_back(nums[i]);

            if (ans1.size() == 3) {
                int mini = *min_element(ans1.begin(), ans1.end());
                int maxi = *max_element(ans1.begin(), ans1.end());

                if (maxi - mini > k) {
                    return {};
                }

                ans.push_back(ans1);
                ans1.clear();
            }
        }

        //if (!ans1.empty()) return {};

        return ans;
    }
};
