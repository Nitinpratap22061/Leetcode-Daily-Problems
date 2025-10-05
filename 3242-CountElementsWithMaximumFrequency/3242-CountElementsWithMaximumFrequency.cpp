// Last updated: 10/5/2025, 8:50:36 AM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for (int num : nums) {
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        }
        int ans = 0;
        for (auto element : mp) {
            if (element.second == maxFreq) {
                ans += maxFreq;
            }
        }
        return ans;
    }
};
