// Last updated: 10/5/2025, 8:55:42 AM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        
        for (int i = 1; i <= n / 2; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        
        if (n % 2 != 0) {
            ans.push_back(0);
        }
        
        return ans ; 
    }
};
