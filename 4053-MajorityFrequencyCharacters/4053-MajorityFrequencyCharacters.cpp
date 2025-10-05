// Last updated: 10/5/2025, 8:48:02 AM
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        unordered_map<int, vector<char>> mp;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                mp[freq[i]].push_back('a' + i);
            }
        }

       
        int bestSize = 0;
        int bestFreq = 0;
        vector<char> result;

        for (auto &entry : mp) {
            int f = entry.first;
            int sz = entry.second.size();

            if (sz > bestSize || (sz == bestSize && f > bestFreq)) {
                bestSize = sz;
                bestFreq = f;
                result = entry.second;
            }
        }

        string ans;
        for (char c : result) ans.push_back(c);
        return ans;
    }
};
