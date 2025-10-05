// Last updated: 10/5/2025, 8:50:10 AM
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0, total = nums.size();

        while(nums[0] > 0) {
            vector<int> digitCount(10,0);

           
            for(auto &it : nums) {
                digitCount[it%10]++;
                it /= 10; 
            }

            long long curr = 0;
            for(auto freq : digitCount) {

                if(freq > 0) { 
                  curr += freq*(total - freq); 
                }
            }
        
         ans += curr/2; 
        }
     return ans;
    }
};