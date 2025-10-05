// Last updated: 10/5/2025, 8:56:39 AM
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0); 
        vector<int> trustedByCount(n + 1, 0); 

    
        for ( auto relation : trust) {
            int a = relation[0];
            int b = relation[1];
            trustCount[a]--; 
            trustedByCount[b]++; 
        }
        for (int i = 1; i <= n; i++) {
            if (trustedByCount[i] == n - 1 && trustCount[i] == 0) {
                return i; 
            }
        }

        return -1; 
    }
};
