// Last updated: 10/5/2025, 8:57:09 AM
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                even.push_back(nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }
        for(int i=0;i<even.size();i++)
        {
            res.push_back(even[i]);
        }
         for(int i=0;i<odd.size();i++)
        {
            res.push_back(odd[i]);
        }
         return res;
        
    }
};