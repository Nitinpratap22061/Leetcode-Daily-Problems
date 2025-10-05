// Last updated: 10/5/2025, 8:50:50 AM
class Solution {
public:
    int minChanges(string s) {
       int count = 0;
        for(int i=1 ; i<s.size() ; i=i+2)
        {
            if(s[i]!=s[i-1])
            {
                count++;
             
            }

        }
        return count ; 
    }
};