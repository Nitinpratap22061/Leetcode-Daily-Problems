// Last updated: 10/5/2025, 8:51:24 AM
class Solution {
public:
   int n ; 

    bool isValid(int mid , vector<int>& nums , int p )
    {
        int cp = 0 ;
        int i = 0 ;
        while(i<n-1)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                cp++;
                i+=2;
            }
            else
            {
                i++;
            }
        }
        return cp>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
     n = nums.size() ; 
        sort(nums.begin() , nums.end());
        int left = 0 ; 
        int right = nums[n-1] - nums[0];
        int res = INT_MIN; 

        while(left<=right)
        {
            int mid = left+(right-left)/2 ; 
            if(isValid(mid , nums , p))
            {
                res = mid ; 
                right = mid-1 ;
            }
            else
            {
                left = mid+1 ; 
            }


        }
        return res;
        
    }
};