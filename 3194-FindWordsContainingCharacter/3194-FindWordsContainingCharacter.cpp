// Last updated: 10/5/2025, 8:50:46 AM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i = 0 ; i<words.size() ; i++)
        {
            string str = words[i];
             if (find(str.begin(), str.end(), x) != str.end())
             {
                ans.push_back(i);
             }
        }
        return ans;
        
    }
};