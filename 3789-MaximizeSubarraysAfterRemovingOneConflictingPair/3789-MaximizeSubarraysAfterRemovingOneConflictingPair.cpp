// Last updated: 10/5/2025, 8:48:57 AM

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {

        long long valid = 0 ; 
        vector<vector<int>>cpairs(n+1) ; 
        for(auto &p : conflictingPairs)
        {
            int a = min(p[0] , p[1]) ; 
            int b = max(p[0] , p[1]) ; 
            cpairs[b].push_back(a) ; //(5--->4)

        }
        int maxcp =0 ;
        int smaxcp = 0 ;
        vector<long long>bonus(n+1);//cp htane pe gain 

        for(int end = 1 ; end<=n ; end++)
        {
            for(int &u : cpairs[end])
            {
                if(u>=maxcp)
                {
                    smaxcp = maxcp ; 
                    maxcp = u ;
                }
                else if(u>smaxcp)
                {
                    smaxcp = u ; 
                }
            }

            valid += end - maxcp;
            bonus[maxcp]+=maxcp-smaxcp;
        }

        return valid+*max_element(begin(bonus) , end(bonus));




       
    }
};