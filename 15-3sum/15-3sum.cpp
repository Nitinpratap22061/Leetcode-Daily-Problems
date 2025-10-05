// Last updated: 10/5/2025, 9:02:50 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        set<tuple<int, int, int>> st;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int end = nums.size() - 1;
            while (j < end) {
                int sum = nums[i] + nums[j] + nums[end];
                if (sum == 0) {
                    st.insert({nums[i], nums[j], nums[end]});
                    j++;
                    end--;

                } else if (sum < 0) {
                    j++;
                } else {
                    end--;
                }
            }
        }

        // now
        vector<vector<int>> vec2D;

        for (const auto& [a,b,c] : st) {
            vec2D.push_back({a,b,c});
        }
        return vec2D;
    }
};