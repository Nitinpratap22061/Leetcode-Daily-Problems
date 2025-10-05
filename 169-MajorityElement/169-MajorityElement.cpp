// Last updated: 10/5/2025, 9:00:43 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int help=nums[i];
            mp[help]++;
        }
        for(auto itr:mp)
        {
            if(itr.second>n/2)
            {
                ans=itr.first;
            }
        }
        return ans;
        
        
    }
};