// Last updated: 10/5/2025, 8:54:40 AM
class Solution {
public:
    int maxDepth(string& s) {
        int ans=0, p=0;
        for(char c: s){
            p+=(c=='(')-(c==')');
            ans=max(ans, p);
        }
        return ans;  
    }
};
