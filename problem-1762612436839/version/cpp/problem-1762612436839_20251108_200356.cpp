// Last updated: 11/8/2025, 8:03:56 PM
class Solution {
public:
    int minMoves(vector<int>& nums) {
    //element equal krna

         int max_ele = *max_element(nums.begin(), nums.end())  ; 
       int ans = 0 ; 
        for(auto ele : nums)
            {
                 ans+=(max_ele-ele) ; 
            }
        return ans ; 
      
        
    }
};