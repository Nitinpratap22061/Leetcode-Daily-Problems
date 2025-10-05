// Last updated: 10/5/2025, 8:58:17 AM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        int n=nums.size();
        int sum=0;
        int total=(n)*(n+1);
        int totalsum=total/2;
       set<int>s;
       for(int i=0;i<nums.size();i++)
       {
           s.insert(nums[i]);
       }
       for(auto element:s)
       {
           sum=sum+element;
       }
       int res=totalsum-sum;
       ans.push_back(res);
       return ans;
    }
};