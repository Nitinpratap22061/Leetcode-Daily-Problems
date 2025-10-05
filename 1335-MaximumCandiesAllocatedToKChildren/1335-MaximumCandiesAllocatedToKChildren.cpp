// Last updated: 10/5/2025, 8:55:54 AM
class Solution {
public:
   bool candiesPoss(vector<int>& candies , int mid , long long k)
   {
        long long count = 0;
        for(int i = 0 ; i<candies.size() ; i++)
        {
             count += candies[i] / mid ;
             if(count>=k)
             {
                return true;
             }
        }
        return false;
   }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1 ;
        int r = *max_element(begin(candies) , end(candies)) ;
        int res = 0;
        while(l<=r)
        {
            int mid = l+(r-l)/2 ; 
            if(candiesPoss(candies , mid , k))
            {
                res = mid ; 
                l =mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res ; 
        
    }
};