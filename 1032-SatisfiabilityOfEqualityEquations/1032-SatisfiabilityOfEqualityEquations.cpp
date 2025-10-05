// Last updated: 10/5/2025, 8:56:45 AM
class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        vector<int> parent(26);
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (string& s : equations) {
            if (s[1] == '=') {
                // union krna parega
                Union(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }
        for (string& s : equations) {
            if (s[1] == '!') {
                // find parent;
                char first = s[0];
                char second = s[3];
                int parent_first = find(first - 'a', parent);
                int parent_second = find(second - 'a', parent);

                if (parent_first == parent_second) {
                    return false;
                }
            }
        }
        return true;
    }
};