// Last updated: 11/16/2025, 11:12:20 AM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN ;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1;j<n ; j++)
            {
                for(int k = j+1 ; k<n ; k++)
                {
                    int c = min({nums[i], nums[j] , nums[k]}) ; 
                    int total = nums[i]+nums[j]+nums[k];
                    int help = total-c ; 

                    ans = max(ans , help-c);

                }
            }
        }
        return ans ; 
        
    }
};