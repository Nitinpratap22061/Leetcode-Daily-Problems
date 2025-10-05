// Last updated: 10/5/2025, 8:48:54 AM
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        map<char,int>mp;
        for(auto &ch : s)
        {
            mp[ch]++;
        }
        string firsthalf = "";
        string middle = "";
        for(auto &it:mp)
        {
            char ch = it.first;
            int count = it.second ; 

            if(count%2==1)
            {
                middle = ch ;
            }
            firsthalf +=string(count/2,ch);
        }
    
        string lasthalf = firsthalf;
        reverse(lasthalf.begin(), lasthalf.end());
        return firsthalf+middle+lasthalf;
        
    }
};