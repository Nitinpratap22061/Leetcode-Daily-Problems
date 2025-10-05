// Last updated: 10/5/2025, 8:48:18 AM
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        unordered_map<int,int> mp;
        for (int x : nums) 
            {
                mp[x]++;
            }

        int groups = n / k;
        for (auto &p : mp) {
            if (p.second > groups) 
            {
                return false; 
            }
        }
        return true;
    }
};
