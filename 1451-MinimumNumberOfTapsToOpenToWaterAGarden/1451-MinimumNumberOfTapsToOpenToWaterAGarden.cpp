// Last updated: 10/5/2025, 8:55:36 AM
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>helper(n+1 , 0 ) ;
        for(int i = 0 ; i<=n ; i++ )
        {
          int lower = max(0 , i-ranges[i] ) ;
          int higher = min(n , i+ranges[i])  ;
          helper[lower] = max(helper[lower] , higher) ;
        }
         int taps = 0 ;
         int maxend = 0 ;
         int curr = 0 ;
         for(int i = 0 ; i<=n ; i++)
         {
            if(i>maxend)
            {
                return -1;
            }
            if(i>curr)
            {
                taps++;
                curr = maxend;
            }
            maxend = max(maxend , helper[i]) ;
         }
        return taps ;
    }
};