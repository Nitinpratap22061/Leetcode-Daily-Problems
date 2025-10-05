// Last updated: 10/5/2025, 8:57:50 AM
class Solution {
public:
unordered_map<char,int>mp;
int count=0;
    int numJewelsInStones(string jewels, string stones) {
        for(int i=0 ; i<jewels.size() ; i++)
        {
           int character = jewels[i];
           mp[character]++;
        }
        for(int i=0 ; i<stones.size();i++)
        {
            if(mp.find(stones[i])!=mp.end())   //present jewel me
            {
              count++;  
            } 
        }
        return count;
        
    }
};