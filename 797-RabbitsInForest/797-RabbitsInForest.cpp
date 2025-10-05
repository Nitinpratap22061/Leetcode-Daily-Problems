// Last updated: 10/5/2025, 8:57:48 AM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp ; 
        for(int &x:answers)
        {
            mp[x]++;
        }
        int total = 0 ;
        for(auto &it : mp)
        {
            int x = it.first;
            int count = it.second;
            int gs = x+1;
            int group = ceil((double)count/gs);
            total+=group*gs;
        }
        return total;
        
    }
};