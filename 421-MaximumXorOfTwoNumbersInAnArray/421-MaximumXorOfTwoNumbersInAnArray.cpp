// Last updated: 10/5/2025, 8:59:06 AM
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0; 
        int mask = 0;

        for (int bit = 31; bit >= 0; bit--) {
            mask |= (1 << bit); 
            unordered_set<int> prefixes;

          
            for (int num : nums) {
                prefixes.insert(num & mask);
            }

           
            int candidate = maxXor | (1 << bit);

            bool found = false;
            for (int p : prefixes) {
                if (prefixes.count(p ^ candidate)) {
                    found = true;
                    break;
                }
            }

            if (found) maxXor = candidate;
        }

        return maxXor;
    }
};
