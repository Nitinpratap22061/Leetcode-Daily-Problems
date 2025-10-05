// Last updated: 10/5/2025, 8:48:21 AM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi= 0;

        while (j < n) {
           
            if ((long long)nums[j] <= (long long)nums[i] * k) {
                int len = j-i+1;
                maxi= max(maxi, len);
                j++;
            } else {
                i++;
            }
        }

        int ans = n - maxi;

        return ans;
    }
};
