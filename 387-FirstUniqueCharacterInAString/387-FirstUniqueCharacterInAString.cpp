// Last updated: 10/5/2025, 8:59:20 AM
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
               if(freq[s[i]-'a']==1)
               return i;
        }
        return -1;
    }
};