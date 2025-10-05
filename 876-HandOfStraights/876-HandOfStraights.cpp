// Last updated: 10/5/2025, 8:57:31 AM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;  // Sorted map for smallest card access
        for (int card : hand) {
            freq[card]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;  // smallest card
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;
                if (freq[card] == 0) return false;
                freq[card]--;
                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};
