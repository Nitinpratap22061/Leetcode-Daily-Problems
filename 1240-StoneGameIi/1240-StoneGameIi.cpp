// Last updated: 10/5/2025, 8:56:13 AM
class Solution {
public:
 int t[2][101][101];
    int solve(int person, int i, int M, vector<int>& piles) {
        int size = piles.size();
        if (i >= size) {
            return 0;
        }
        if(t[person][i][M]!=-1)
        {
            return t[person][i][M];
        }
        
        int stones = 0;
        int result = (person == 1) ? INT_MIN : INT_MAX;

        for (int x = 1; x <= min(2 * M, size - i); x++) {
            stones += piles[i + x - 1];  // Fixed indexing error
            
            if (person == 1) {
                result = max(result, stones + solve(0, i + x, max(M, x), piles));
            } else {
                result = min(result, solve(1, i + x, max(M, x), piles));
            }
        }
        return t[person][i][M]=result;
    }

    int stoneGameII(vector<int>& piles) {
        int M = 1;
        memset(t,-1,sizeof(t));
        return solve(1, 0, M, piles);
    }
};
