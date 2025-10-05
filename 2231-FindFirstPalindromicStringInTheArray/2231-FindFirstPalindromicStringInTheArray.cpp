// Last updated: 10/5/2025, 8:53:07 AM
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words)
        {
            string s1=s;
            reverse(s1.begin(),s1.end());
            if(s==s1)
            {
                return s;
            }
        }
        return "";
        
    }
};