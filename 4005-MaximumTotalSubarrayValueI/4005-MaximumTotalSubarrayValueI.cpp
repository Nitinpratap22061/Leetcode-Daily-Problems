// Last updated: 10/5/2025, 8:48:09 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        long long maxi = *max_element(begin(nums) , end(nums)) ; 
        long long  mini = *min_element(begin(nums) , end(nums)) ;  

        return (long long)((maxi-mini)*(long long)k) ; 
        
    }
};