// Last updated: 10/5/2025, 8:56:09 AM
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> help = arr;
        if(arr.size()==0)
        {
            return {};
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        mp[arr[0]] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) {
                mp[arr[i]] = mp[arr[i - 1]] + 1;
            } else {
                mp[arr[i]] = mp[arr[i - 1]];
            }
        }
        for (int i = 0; i < help.size(); i++) {
            ans.push_back(mp[help[i]]);
        }
        return ans;
    }
};
