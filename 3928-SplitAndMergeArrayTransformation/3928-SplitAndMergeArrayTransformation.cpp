// Last updated: 10/5/2025, 8:48:33 AM
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        queue<vector<int>> q;
        q.push(nums1);

        set<vector<int>> visited;
        visited.insert(nums1);

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();

                if (curr == nums2) {
                    return steps;
                }

                int m = curr.size();
                for (int l = 0; l < m; l++) {
                    for (int r = l; r < m; r++) {
                        vector<int> cut(curr.begin() + l, curr.begin() + r + 1);

                        vector<int> remaining;
                        remaining.insert(remaining.end(), curr.begin(),
                                         curr.begin() + l);
                        remaining.insert(remaining.end(), curr.begin() + r + 1,
                                         curr.end());

                        for (int pos = 0; pos <= (int)remaining.size(); pos++) {
                            vector<int> temp = remaining;
                            temp.insert(temp.begin() + pos, cut.begin(),
                                        cut.end());

                            if (!visited.count(temp)) {
                                visited.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            steps++;
        }

        return -1; 
    }
};
