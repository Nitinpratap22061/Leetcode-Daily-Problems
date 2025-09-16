// Last updated: 9/16/2025, 5:47:15 PM
#include <vector>
#include <numeric>  // for gcd
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            res.push_back(curr);
            
            while (res.size() >= 2) {
                int prev = res[res.size() - 2];
                int last = res.back();
                int GCD = gcd(prev, last);

                if (GCD > 1) {
                    res.pop_back();
                    res.pop_back();
                    long long lcm = (1LL * prev / GCD) * last;
                    res.push_back((int)lcm);
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
