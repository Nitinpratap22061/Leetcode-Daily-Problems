// Last updated: 10/5/2025, 8:50:19 AM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& pair : freqMap) {
            freqs.push_back(pair.second);
        }

        sort(freqs.begin(), freqs.end());

        int res = INT_MAX;
        int n = freqs.size();

        for (int i = 0; i < n; ++i) {
            int target = freqs[i];
            int deletions = 0;

            // Delete all frequencies < target
            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];
            }

            // Delete from all frequencies > target + k
            for (int j = i; j < n; ++j) {
                if (freqs[j] > target + k) {
                    deletions += freqs[j] - (target + k);
                }
            }

            res = min(res, deletions);
        }

        return res;
    }
};
