// Last updated: 10/5/2025, 8:55:03 AM
class Solution {
public:
const int MOD = 1e9+7;
    int fastexpo(int a, int b) {
    if (b == 0)
        return 1;

    int half = fastexpo(a, b / 2);

    if (b % 2 == 0) {
       return (1LL * half * half) % MOD;

    } else {
        return (1LL*a * half * half)%MOD;
    }
}

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()) ; 
        int n = nums.size() ; 
        int l = 0 ; 
        int r = n-1 ; 
        int result = 0 ; 
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                result = (result + fastexpo(2, r - l)) % MOD;


                l++;
            }
            else
            {
                r--;
            }
        }
        return result%MOD ; 

        
    }
};