// Last updated: 9/13/2025, 11:40:00 AM
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        int maxi1=0;
        int maxi2=0;
        for(auto &ch:s)
            {
                mp[ch]++;
            }
        for(auto &ch:s)
            {
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                {
                    maxi1 = max(maxi1 , mp[ch]);
                }
                else
                {
                    maxi2 = max(maxi2 , mp[ch]);
                }
                
                
            }
        return maxi1+maxi2;
        
    }
};