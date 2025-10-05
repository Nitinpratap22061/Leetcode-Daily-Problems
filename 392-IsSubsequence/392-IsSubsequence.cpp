// Last updated: 10/5/2025, 8:59:18 AM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        int j=0;
        for(int i=0;i<t.size() and j<s.size();i++)
        {
            if(s[j]==t[i])
            {
                j++;
            }
        }
        return (j==s.size());   
            


        
    }
};