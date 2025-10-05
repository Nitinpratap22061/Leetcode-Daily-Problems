// Last updated: 10/5/2025, 8:59:19 AM
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        char ans;
        for(int i=0;i<t.size();i++)
        {
            char ch=t[i];
            mp[ch]++;
        }
        for(int i=0;i<s.size();i++)
        {
            char che=s[i];
            mp[che]--;
        }
        for(auto itr:mp)
        {
            if(itr.second==1)
            {
                ans=itr.first;
            }

        }
        return ans;



        
    }
};