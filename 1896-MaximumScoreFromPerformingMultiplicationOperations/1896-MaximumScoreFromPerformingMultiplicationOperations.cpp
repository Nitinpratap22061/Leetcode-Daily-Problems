// Last updated: 10/5/2025, 8:54:02 AM
class Solution {
public:
    unordered_map<string, int> mp;

    int solve(int i, int j, int op, vector<int>& nums, vector<int>& multipliers) {
        if (op == multipliers.size()) return 0;

        string key = to_string(i) +"_"+to_string(j)+"_"+to_string(op) ; 

        if(mp.count(key))
        {
            return mp[key] ; 
        }


        int left = nums[i] * multipliers[op] + solve(i + 1, j, op + 1, nums, multipliers);
        int right = nums[j] * multipliers[op] + solve(i, j - 1, op + 1, nums, multipliers);

        return mp[key] = max(left, right);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        mp.clear();
        return solve(0, n - 1, 0, nums, multipliers);
    }
};
