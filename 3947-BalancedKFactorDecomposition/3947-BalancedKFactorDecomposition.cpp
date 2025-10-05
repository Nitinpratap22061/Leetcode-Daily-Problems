// Last updated: 10/5/2025, 8:48:26 AM
class Solution {
public:
    vector<int> ans;
    int sulmariton;

    bool dfs(vector<int>& curr, int remaining, int k, int start, int candidate) {
        if (curr.size() == k - 1) {
            if (remaining >= 1) {
                curr.push_back(remaining);
                int mx = *max_element(curr.begin(), curr.end());
                int mn = *min_element(curr.begin(), curr.end());
                if (mx - mn <= candidate) {
                    ans = curr;
                    curr.pop_back();
                    return true;
                }
                curr.pop_back();
            }
            return false;
        }
        for (int i = start; i <= remaining; i++) {
            if (remaining % i != 0) continue;
            curr.push_back(i);
            if (dfs(curr, remaining / i, k, i, candidate)) {
                curr.pop_back();
                return true;
            }
            curr.pop_back();
        }
        return false;
    }

    bool solve(int candidate, int n, int k) {
        ans.clear();
        vector<int> curr;
        return dfs(curr, n, k, 1, candidate);
    }

    vector<int> minDifference(int n, int k) {
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (solve(mid, n, k))
            {
                high = mid;
            }
            else 
            {
                low = mid + 1;
            }
        }
        solve(low, n, k);
        return ans;
    }
};
