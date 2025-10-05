// Last updated: 10/5/2025, 8:52:52 AM
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res; 
        res.push_back(nums[0]); 

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i]; 
        
            while (!res.empty()) {
                int prev = res.back(); 
                int GCD = gcd(prev, curr); 
                
                if (GCD > 1) {
                    res.pop_back(); 
                    long long lcm = (1LL * prev / GCD) * curr;
                    curr = (int)lcm;  
                } else {
                    break;
                }
            }
            
            res.push_back(curr); 
        }

        return res;
    }
};
