// Last updated: 10/5/2025, 8:52:55 AM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size() ;
        int count = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                if(nums[i]==nums[j] && (i*j)%k==0)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};