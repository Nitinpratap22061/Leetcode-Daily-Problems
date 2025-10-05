// Last updated: 10/5/2025, 8:59:54 AM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int range=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        int totalsum=(range*(range+1))/2;
        int ans=totalsum-sum;
        return ans;
        
    }
};