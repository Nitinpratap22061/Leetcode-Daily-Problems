// Last updated: 10/5/2025, 8:50:56 AM
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
       int  m = values.size();
       int  n = values[0].size();

         vector<int>helper ; 
         
         for(int i = 0 ; i<m ; i++)
         {
            for(int j = 0 ; j<n ; j++)
            {
                helper.push_back(values[i][j]);
            }
         }

         sort(begin(helper) , end(helper)) ;
         long long k = helper.size() ; 
         long long sum = 0 ; 
         for(long long i = 1 ; i<=k ; i++)
         {
            sum=(long long)(sum+(long long)(helper[i-1]*i));
         }
        return sum;
    }
};