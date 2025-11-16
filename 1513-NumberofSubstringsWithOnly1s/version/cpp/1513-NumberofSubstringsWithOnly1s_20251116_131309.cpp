// Last updated: 11/16/2025, 1:13:09 PM
class Solution {
public:
  const int mod  = 1e9+7 ; 
    int numSub(string s) {

        int n = s.size() ; 
           int cons = 0 ; 
           long long ans =  0 ; 
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='1')
            {
                cons++ ;
            }
            else
            {
               ans += (1LL * cons * (cons + 1) / 2)%mod;

                cons = 0 ; 
            }

        }

         ans += (1LL * cons * (cons + 1) / 2)%mod;

        return ans%mod ; 


        
    }
};