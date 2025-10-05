// Last updated: 10/5/2025, 8:55:28 AM
class Solution {
public:
    int t[501][501] ;
    int n;
    int solve(vector<int>& satisfaction, int idx, int count) {

        if (idx >= n) {
            return 0;
        }
        if(t[idx][count]!=-1)
        {
            return t[idx][count];
        }
        int take = satisfaction[idx] * count +
                   solve(satisfaction, idx + 1, count + 1);
        int skip = solve(satisfaction , idx+1 , count);

        return t[idx][count] = max(take,skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        n = satisfaction.size();
        memset(t,-1,sizeof(t));
        return solve(satisfaction, 0, 1);
    }
};