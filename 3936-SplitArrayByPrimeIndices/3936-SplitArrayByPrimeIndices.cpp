// Last updated: 10/5/2025, 8:48:29 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool>isprime(n, true);
         isprime[0] = false;
         isprime[1] = false;

        for (int i = 2; 1LL * i * i < (n); i++) {
    if (isprime[i]) {
        for (long long j = 1LL * i * i; j < n; j += i) {
            isprime[j] = false;
        }
    }
}


        long long a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (isprime[i]) 
            {
                a += nums[i];
            }
            else 
            {
                b += nums[i];
            }
        }

        return abs(a - b);
    }
};
