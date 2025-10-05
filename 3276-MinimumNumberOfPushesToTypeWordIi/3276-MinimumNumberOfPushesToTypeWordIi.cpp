// Last updated: 10/5/2025, 8:50:32 AM
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> frequencies;
        for (auto& entry : freq) {
            frequencies.push_back(entry.second);
        }

       
        sort(frequencies.rbegin(), frequencies.rend());

        int totalPushes = 0;
        int keys[8] = {0}; 

        for (int i = 0; i < frequencies.size(); ++i) {
            int keyIndex = i % 8;
            int position = keys[keyIndex]++;
            totalPushes += frequencies[i] * (position + 1);
        }

        return totalPushes;
    }
};
