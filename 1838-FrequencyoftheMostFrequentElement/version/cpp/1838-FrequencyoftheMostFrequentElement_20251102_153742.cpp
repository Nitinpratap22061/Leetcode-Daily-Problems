// Last updated: 11/2/2025, 3:37:42 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1, high = n, ans = 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (solve(nums, k, mid)) {
                ans = mid;
                low = mid + 1;  // try for larger frequency
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool solve(vector<int>& nums, int k, int freq) {
        long long total = 0;
        for (int i = 0; i < freq - 1; i++) total += nums[i];

        for (int j = freq - 1; j < nums.size(); j++) {
            total += nums[j];
            long long cost = 1LL * nums[j] * freq - total;

            if (cost <= k) return true;

            total -= nums[j - freq + 1];
        }
        return false;
    }
};
