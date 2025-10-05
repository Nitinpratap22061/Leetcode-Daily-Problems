// Last updated: 10/5/2025, 8:49:51 AM
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, vector<int>> playerColors;
        
        
        for (const auto& p : pick) {
            playerColors[p[0]].push_back(p[1]);
        }

        int finalCount = 0;
        for (int i = 0; i < n; ++i) {
            if (playerColors.find(i) != playerColors.end()) {
                unordered_map<int, int> colorCount;
                for (int color : playerColors[i]) {
                    colorCount[color]++;
                }
                for (const auto& entry : colorCount) {
                    if (entry.second >= i + 1) {
                        finalCount++;
                        break; 
                    }
                }
            }
        }

        return finalCount;
    }
};
