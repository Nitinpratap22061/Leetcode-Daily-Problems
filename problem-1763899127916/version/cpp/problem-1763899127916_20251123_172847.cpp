// Last updated: 11/23/2025, 5:28:47 PM
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {

        int n = nums.size() ; 

        int x= 0 ; 
        int even  = 0 ; 
        int odd = 0 ; 

        int diff = 0 ; 

        int maxi = 0 ; 

        map<pair<int,int> , int>mp ; 

        mp[{0,0}] = -1 ; 

        for(int i = 0 ; i<n ; i++)
            {
                int ele = nums[i] ; 

                if(ele%2==0)
                {
                    even++ ; 
                }
                else
                {
                    odd++ ; 
                }

                diff = even - odd ; 
                x = x^ele ; 
                if(mp.find({x,diff})!=mp.end())
                {
                    maxi = max(maxi , i-mp[{x,diff}]) ; 
                }
                else
                {
                    mp[{x,diff}] = i ; 
                }
            }

        return maxi ; 
        
    }
};