// Last updated: 10/5/2025, 9:02:21 AM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(begin(temp),end(temp));
            mp[temp].push_back(strs[i]);
        }
        for(auto itr:mp)
        {
            res.push_back(itr.second);
        }
        return res;
        
    }
};