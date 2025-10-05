// Last updated: 10/5/2025, 8:50:40 AM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int i = 0 ; 
        int j = 0 ; 
        int res = 0 ; 
        unordered_map<int,int>mp ; 
        while(j<n)
        {
            mp[nums[j]]++ ; 
            if(mp[nums[j]]>k)
            {
                while(mp[nums[j]]>k)
                {
                    mp[nums[i]]--;
                    i++;
                }
            }
            res = max(res,j-i+1);
            j++;

        }
        return res;
    }
};