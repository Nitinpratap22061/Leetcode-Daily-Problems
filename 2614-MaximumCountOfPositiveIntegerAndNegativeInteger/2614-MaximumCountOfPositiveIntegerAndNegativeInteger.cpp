// Last updated: 10/5/2025, 8:51:44 AM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countP = 0 ;
        int countN = 0 ;
        for(auto ele : nums)
        {
            if(ele < 0)
            {
                countN ++ ;
            }
            else if(ele > 0)
            {
                countP++;
            }
       }
       return max(countP , countN) ; 
    }
};