// Last updated: 10/5/2025, 8:50:44 AM
class Solution {
public:
long long swap=0;
long long black=0;





    long long minimumSteps(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                swap+=black;
            }
           
        
        else
        {
            black++;
        }

        }
    
     return swap;   
    }
};
