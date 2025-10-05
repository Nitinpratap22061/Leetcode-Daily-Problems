// Last updated: 10/5/2025, 9:01:11 AM
class Solution {
public:
    void fillNeighbour(queue<string>& q, string &curr, set<string>& st) {
        for (int i = 0; i < curr.size(); i++) {
            char original = curr[i];

            
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;

                curr[i] = c;
                if (st.find(curr) != st.end()) {
                    q.push(curr);
                    st.erase(curr); 
                }
            }
            curr[i] = original; 
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       set<string> st(begin(wordList), end(wordList));
        if (st.find(endWord) == st.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 0; 

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) {
                    return level+1;
                }
                fillNeighbour(q, curr, st);
            }
            level++;
        }
        return 0; 
    }
};
