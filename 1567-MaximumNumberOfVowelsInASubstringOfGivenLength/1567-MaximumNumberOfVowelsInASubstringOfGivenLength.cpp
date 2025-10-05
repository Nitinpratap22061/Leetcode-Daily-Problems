// Last updated: 10/5/2025, 8:55:13 AM
class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0 ; 
        int res = 0 ;
        int n = s.size();
        int i = 0 ;
        int j = 0 ;
        while(j<n)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                count++;
            }
            if(j-i+1>k) //shrink
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    count--;
                }
                i++;

            }
             if(j-i+1==k)
            {
                res = max(res,count);
            }
            j++;
        }
        return res;
        
    }
};