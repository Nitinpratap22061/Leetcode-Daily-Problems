// Last updated: 10/5/2025, 8:55:34 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0 ; 
        int j = 0;
        int n = s.size();
        vector<int>mp(3,0);
        int res = 0 ;
        while(j<n)
        {
            mp[s[j]-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
                res+=(n-j);
                mp[s[i]-'a']--;
                i++;
            }
            j++;
            
        }
        return res;
        
    }
};