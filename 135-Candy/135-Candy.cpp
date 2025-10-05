// Last updated: 10/5/2025, 9:01:03 AM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans1(n, 1);  // Left to right
        vector<int> ans2(n, 1);  // Right to left
        vector<int> res(n, 0);   // Final result

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans1[i] = ans1[i - 1] + 1;
            }
        }

       
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                ans2[i] = ans2[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            res[i] = max(ans1[i], ans2[i]);
        }

        return accumulate(res.begin(), res.end(), 0);
    }
};
