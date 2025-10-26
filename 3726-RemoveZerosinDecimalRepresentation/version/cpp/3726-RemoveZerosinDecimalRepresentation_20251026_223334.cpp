// Last updated: 10/26/2025, 10:33:34 PM
class Solution {
public:
    long long removeZeros(long long n) {

        string helper = to_string(n) ;
        string ans = "" ;  
        for(int i = 0 ; i<helper.size() ; i++)
        {
            if(helper[i]!='0')
            {
                ans+=helper[i] ; 

            }
        }
        long long  res = (long long)stoll(ans) ; 
        return res ; 
        
    }
};