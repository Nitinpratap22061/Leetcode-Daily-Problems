// Last updated: 10/5/2025, 8:51:29 AM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size() ; 
        sort(nums.begin() , nums.end());
        long long res = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            auto idx = lower_bound(begin(nums)+i+1 , end(nums) , lower-nums[i])-begin(nums);
            int x = idx-i-1 ;
            idx = upper_bound(begin(nums)+i+1 , end(nums) , upper-nums[i])-begin(nums);
            int y = idx-i-1;
            res+=y-x;
        }
        return res;

        
    }
};