// Last updated: 10/5/2025, 8:53:26 AM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
          int n = nums.size()  ;
          int maxi = INT_MIN ; 

          for(int i = 0 ; i<n ; i++)
          {
            for(int j = i+1 ; j<n ; j++)
            {
            if(nums[i]<nums[j])
            {
                int diff = nums[j]-nums[i];
                maxi = max(maxi,diff);

            }
            }
          }
          return maxi!=INT_MIN?maxi:-1 ; 
    }
};