// Last updated: 10/5/2025, 8:55:07 AM
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>ans;
        for(int i= 1 ; i<=n ; i++ )
        {
            if(n%i == 0)
            {
                ans.push_back(i);
            }
        }
         if(ans.size()>=k)
         {
        return ans[k-1];
         }
         return -1;
    }
};