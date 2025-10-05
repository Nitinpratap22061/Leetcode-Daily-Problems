// Last updated: 10/5/2025, 8:50:34 AM
class Solution {
public:
    long long solve(string &str , int limit , string &s)
    {
        if(str.length()<s.length())
        {
            return 0 ; 
        }
        long long count = 0 ;
        string trail = str.substr(str.length() - s.length()) ; 
        int reml = str.length() - s.length();
        for(int i = 0 ; i<reml ; i++)
        {
            int digit = str[i] - '0' ;
            if(digit<=limit)
            {
                count+=digit * pow(limit+1 , reml-i-1);
            }
            else
            {
                count+=pow(limit+1 , reml-i);
                return count ; 
            }
        }
        if(trail >= s)
        {
            count+=1;
        }
        return count ; 
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int n = s.size() ; 
        string startstr = to_string(start-1) ;
        string finishstr = to_string(finish) ;
        return solve(finishstr , limit , s) - solve(startstr , limit , s);
        
    }
};