// Last updated: 10/5/2025, 8:52:00 AM
class Solution {
public:
    int n ; 
    long long find(vector<int>& nums, vector<int>& cost , int target)
    {
        long long costs = 0 ; 
        for(int i = 0 ; i<n ; i++ )
        {
           costs += (long long)abs(nums[i] - target) * (long long)cost[i];

        }
        return costs ; 
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {

     n = nums.size() ; 
     long long low = (long long)*min_element(begin(nums) , end(nums)) ; 
      long long high = (long long)*max_element(begin(nums) , end(nums)) ;
      long long res = INT_MAX ; 

      while(low<=high) 
      {
        long long mid = low+(high-low)/2 ; 
        long long cost1 = find(nums , cost , mid) ; 
        long long cost2 = find(nums , cost , mid+1) ; 
        res = min(cost1,cost2) ; 
        if(cost1>cost2)
        {
            low = mid+1 ; 
        }
        else
        {
            high = mid-1 ; 
        }
      }
        return res==INT_MAX?0:res ; 
    }
};