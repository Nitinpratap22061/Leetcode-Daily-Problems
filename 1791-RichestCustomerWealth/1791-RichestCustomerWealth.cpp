// Last updated: 10/5/2025, 8:54:28 AM
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxsum = INT_MIN;
        for (auto ele : accounts)
        {
            int sum = 0;
        
            for (int i = 0; i < ele.size(); i++) {
                sum = sum + ele[i];
            }
            if (sum > maxsum) {
                maxsum = sum;
            }
        }
        return maxsum;
    }
};