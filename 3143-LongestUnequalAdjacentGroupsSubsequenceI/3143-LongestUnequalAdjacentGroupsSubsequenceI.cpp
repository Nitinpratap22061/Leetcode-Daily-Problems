// Last updated: 10/5/2025, 8:50:53 AM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string>ans;
        int prev = -1;
        for(int i = 0 ; i<n ; i++)
        {
            if(prev==-1 || groups[i]!=prev)
            {
                ans.push_back(words[i]);
                prev = groups[i];
            }

        }
        return ans;
        
    }
};