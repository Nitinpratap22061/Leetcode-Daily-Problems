// Last updated: 10/5/2025, 8:59:35 AM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0 ; i<=n ; i++)
        {
            ans.push_back(__builtin_popcount(i));

        }
        return ans;
        
    }
};