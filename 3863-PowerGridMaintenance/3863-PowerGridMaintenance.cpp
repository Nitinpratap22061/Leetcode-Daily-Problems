// Last updated: 10/5/2025, 8:48:48 AM
class Solution {
public:
    vector<int> parent;
    vector<int> findParent;
    vector<set<int>> onlineInComponent;

    int find(int x) {
        if (findParent[x] != x) {
            findParent[x] = find(findParent[x]);
        }
        return findParent[x];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            // Union smaller set into larger one to reduce time
            if (onlineInComponent[pu].size() < onlineInComponent[pv].size()) {
                swap(pu, pv);
            }
            findParent[pv] = pu;
            onlineInComponent[pu].insert(onlineInComponent[pv].begin(), onlineInComponent[pv].end());
            onlineInComponent[pv].clear();
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        findParent.resize(c + 1);
        onlineInComponent.resize(c + 1);

        // Init DSU and sets
        for (int i = 1; i <= c; ++i) {
            findParent[i] = i;
            onlineInComponent[i].insert(i);
        }

        // Union connections
        for (auto& conn : connections) {
            unite(conn[0], conn[1]);
        }

        vector<bool> isOnline(c + 1, true);
        vector<int> result;

        for (auto& query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 1) {
                if (isOnline[x]) {
                    result.push_back(x);
                } else {
                    int root = find(x);
                    if (onlineInComponent[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*onlineInComponent[root].begin());  // smallest online station
                    }
                }
            } else {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    int root = find(x);
                    onlineInComponent[root].erase(x);
                }
            }
        }

        return result;
    }
};
