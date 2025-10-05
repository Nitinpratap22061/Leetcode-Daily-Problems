// Last updated: 10/5/2025, 8:49:31 AM
class Solution {
public:
   const int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>freq(26,0);
        for(int i = 0 ; i<s.size() ; i++)
        {
            freq[s[i]-'a']++;
        }
        for(int count =1 ; count<=t ; count++)
        {
            vector<int>temp(26,0);
            for(int i = 0 ; i<26 ; i++)
            {
                char ch = i+'a';
                int frequency = freq[i];

                if(ch!='z')
                {
                  temp[(ch+1)-'a'] = (temp[(ch+1)-'a']+frequency) %MOD;
                }
                else
                {
                    temp[0] = (temp[0]+frequency)%MOD;
                    temp[1] = (temp[1]+frequency)%MOD;

                }
            }
            freq = move(temp);

        }
        int res = accumulate(freq.begin() , freq.end() , 0LL)%MOD;
        return res%MOD;
        
        
    }
};