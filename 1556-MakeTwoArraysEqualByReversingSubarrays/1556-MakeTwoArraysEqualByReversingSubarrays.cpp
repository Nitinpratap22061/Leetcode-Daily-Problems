// Last updated: 10/5/2025, 8:55:15 AM
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        unordered_map<int,int>mp;
        for(auto ele:target)
        {
            mp[ele]++;
        }
         for(auto ele:arr)
        {
           mp[ele]--;
           if(mp[ele]<0)
           {
            return false;
           }
          
        }
        return true;
        

        
    }
};