// Last updated: 10/5/2025, 8:54:07 AM
class Solution {
public:
    const int M = 1e9+7 ; 
    int countHomogenous(string s) {
        int n = s.length() ; 
        int res = 0 ; 
        int length = 0 ; 
        for(int i = 0 ; i<n ; i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                length++; 
            }
            else
            {
                length = 1 ; 
            }
            res = (res+length)%M;
        }
        return res ; 
        
    }
};