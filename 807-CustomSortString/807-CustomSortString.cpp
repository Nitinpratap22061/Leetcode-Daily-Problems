// Last updated: 10/5/2025, 8:57:44 AM
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(char &ch:s)
        {
            mp[ch]++;
        }
        string result="";
        for(char &ch:order)
        {
            while(mp[ch]--)
            {
                result.push_back(ch);
            }
        }
        for(char &ch:s)
        {
            if(mp[ch]>0)
            {
                result.push_back(ch);
            }
        }
        return result;


        
    }
};