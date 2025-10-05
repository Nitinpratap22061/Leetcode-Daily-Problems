// Last updated: 10/5/2025, 8:48:43 AM
class Solution {
public:
    const int MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>left,right ; 
        for(auto num : nums)
            {
                right[num]++;
            }

        long long tc = 0 ; 
        for(int i = 0 ; i<nums.size() ; i++)
            {
                int x = nums[i] ; 
                right[x]--;
                int twice = 2*x ; 
                int leftCount = left[twice] ; 
                int rightCount = right[twice] ; 
                tc= (tc+ (1LL*leftCount*rightCount)%MOD)%MOD ; 
                left[x] ++ ;
            }
        return tc%MOD ; 
        
    }
};