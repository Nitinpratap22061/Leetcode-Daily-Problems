// Last updated: 10/5/2025, 8:58:39 AM
class Solution {
public:
    bool checkRecord(string s) {
        int count=0;
        
        for(int i=0 ; i<s.size();i++)
        {
            if(s[i]=='A')
            {
                count++;
            }
            if(count>=2)
            {
                return false;
            }
        }
        if(s.size()<3)
        {
            return true;
        }

        for(int i=0 ; i<s.size()-2;i++)
        {
            if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L')
            {
                return false;
            }
        }
        return true;
        
    }
};