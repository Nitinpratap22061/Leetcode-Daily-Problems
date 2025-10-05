// Last updated: 10/5/2025, 8:48:08 AM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(), friends.end()); 
        vector<int> ans;

        for (int id : order) {
            if (st.count(id)) {   
                ans.push_back(id);
            }
        }
        return ans;
    }
};
