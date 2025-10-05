// Last updated: 10/5/2025, 8:50:41 AM
class Solution {
public:
int maxele=INT_MIN;
    long long countSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            maxele=max(maxele,nums[i]);
        }
        int i=0;
        int j=0;
        long long result=0;
        int countmax=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        while(j<n)
        {
           if(nums[j]==maxele)
           {
            countmax++;
           }
           while(countmax>=k)
           {
            result+=n-j;
            if(nums[i]==maxele)
            {
                countmax--;
            }
            i++;
           }
           j++;


        }
        return result;
        
    }
};