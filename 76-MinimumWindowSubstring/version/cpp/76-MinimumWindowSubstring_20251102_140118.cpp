// Last updated: 11/2/2025, 2:01:18 PM
class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length() ; 
        unordered_map<char,int>mp ; 
        int minws = INT_MAX ; 
        int start_i = 0 ; 
        if(t.length()>n)
        {
            return "" ; 
        }
        for(auto &ch : t)
        {
            mp[ch]++ ; 
        }
        int rc = t.size() ; 
        int i = 0 ; 
        int j = 0 ; 
        while(j<n) 
        {
           char ch = s[j];
           //req tha
           if(mp[ch]>0)
           {
             rc-- ; 
           }
           mp[ch]-- ; 

           while(rc==0)
           {
             int currsz = j-i+1 ; 
             if(minws > currsz)
             {
                minws = currsz ; 
                start_i = i ; 
             }
             mp[s[i]]++ ; 
             if(mp[s[i]]>0)
             {
                rc++ ; 
             }
             i++ ; 
           }
           j++ ; 
        }

        return minws==INT_MAX?"":s.substr(start_i , minws) ; 
        
    }
};