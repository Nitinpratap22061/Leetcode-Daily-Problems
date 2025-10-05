// Last updated: 10/5/2025, 8:50:51 AM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; 

        vector<int> leftmax(n, 0), rightmax(n, 0);

        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], nums[i + 1]);
        }

        long long maxValue = 0;

        for (int j = 1; j < n - 1; j++) {
            long long tripletValue = (1LL * leftmax[j] - nums[j]) * rightmax[j];
            maxValue = max(maxValue, tripletValue);
        }

        return maxValue;
    }
};
