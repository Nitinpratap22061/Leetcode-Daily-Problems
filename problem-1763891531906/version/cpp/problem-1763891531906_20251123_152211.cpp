// Last updated: 11/23/2025, 3:22:11 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
         string first = to_string(n) ; 
        long long sum = 0 ; 
        while(n!=0)
            {
                int helper = n%10 ; 
                sum+=helper ; 
                n = n/10 ; 
            }
       

        string res = "" ; 

        for(int i = 0 ; i<first.size() ; i++)
            {
                if(first[i]!='0')
                {
                    res+=first[i] ; 
                }
            }
        long long number ; 
           if(res.empty())
           {
               number = 0 ; 
           }
        else
           {
           number = stoll(res) ; 
           }

           return number*sum ; 
    }
};