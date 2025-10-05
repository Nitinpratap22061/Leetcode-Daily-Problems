// Last updated: 10/5/2025, 8:53:59 AM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int>mp;
        for(int i=0 ; i<s1.size() ; i++)
        {
            mp[s1[i]]++;
        }
        for(int i=0 ; i<s1.size() ; i++)
        {
            // if(mp.find(s2[i])==mp.end())
            // {
            //     return false;
            // }
            mp[s2[i]]--;
        }
        for(auto ele:mp)
        {
            if(ele.second>=1)
            {
                return false;
            }
        }
        if(s1.size()!=s2.size())
        {
            return false;
        }
        int count = 0;
        for(int i = 0 ;  i<s1.size() ; i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
        }
        if(count>2)
        {
            return false;
        }
        return true;
        
    }
};