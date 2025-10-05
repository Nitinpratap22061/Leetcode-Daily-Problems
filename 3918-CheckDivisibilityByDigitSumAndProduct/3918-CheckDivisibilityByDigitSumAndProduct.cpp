// Last updated: 10/5/2025, 8:48:37 AM
class Solution {
public:
    bool checkDivisibility(int n) {
        string num = to_string(n) ; 
        int ans = 0 ;
        int prod = 1 ; 
        for(int i = 0 ; i<num.size() ; i++)
            {
                int a = (num[i]-'0');
                ans+=a;
                prod*=a;
            }
        int sum = ans+prod ; 
        if(n%sum==0)
        {
            return true ; 
        }

        return false;
    }
};