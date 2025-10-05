// Last updated: 10/5/2025, 9:00:12 AM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int help=nums[i];
            mp[help]++;
        }
        for(auto itr:mp)
        {
            if(itr.second>n/3)
            {
                ans.push_back(itr.first);
            }
        }
        return ans;
        
    }
};