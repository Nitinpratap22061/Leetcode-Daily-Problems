// Last updated: 10/5/2025, 8:49:08 AM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN; 
        int n = nums.size();
        for(int i = 0 ; i<nums.size()-1 ; i++)
        {
            int absolute = abs(nums[i]-nums[i+1]);
            maxi = max(maxi,absolute);

        }
        int help = abs(nums[n-1] - nums[0]) ; 
        maxi = max(maxi , help);

        return maxi ; 
        
    }
};