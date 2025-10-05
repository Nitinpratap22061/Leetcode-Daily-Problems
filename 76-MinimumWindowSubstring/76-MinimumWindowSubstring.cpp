// Last updated: 10/5/2025, 9:01:58 AM
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length() ; 
        int n = t.length() ; 
        int i = 0 ; 
        int j = 0 ; 
        unordered_map<char,int>mp ; 
        for(auto &ch:t)
        {
            mp[ch]++;
        }
        int rc = t.size() ; 
        int minws = INT_MAX ;
        int start_i = 0 ;
        while(j<m)
        {
            char ch = s[j] ; 
            if(mp[ch]>0)
            {
                rc-- ;
            }
            mp[ch]--;

            while(rc == 0 )
            {
                //shrinking phase 
                int ws = j-i+1 ; 
                if(minws>ws)
                {
                    minws = ws ; 
                    start_i = i ; 
                }
                //shrink 
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    rc++;
                }
                i++ ; 

            }
            j++ ; 

        }

          return minws==INT_MAX?"":s.substr(start_i , minws) ; 
        
    }
};