// Last updated: 10/5/2025, 8:52:38 AM
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size() ;
        vector<int>helper(n) ;
        for(int i = 0 ; i<n ; i++)
        {
            helper[i] = capacity[i] - rocks[i] ;
        }
        sort(begin(helper) , end(helper)) ; 
        int bags = 0 ;
        for(int i = 0 ; i<helper.size() ; i++)
        {
            if(additionalRocks-helper[i]>=0)
            {
                bags = bags+1 ;
                additionalRocks = additionalRocks - helper[i] ;
            }

        }
        return bags;
        
    }
};