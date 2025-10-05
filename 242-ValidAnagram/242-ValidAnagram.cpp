// Last updated: 10/5/2025, 9:00:02 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        vector<int>freq1(26,0);
        int flag;
        if(s.length()!=t.length()){
            return false;
        }

        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            freq[index]++;
            int index1=t[i]-'a';
            freq[index1]--;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
       
        
        
    }
};