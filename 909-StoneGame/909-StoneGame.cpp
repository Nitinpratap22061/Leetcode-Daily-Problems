// Last updated: 10/5/2025, 8:57:18 AM
class Solution {
public:
int t[501][501];
    int solve(vector<int>& nums , int i , int j)
    {
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        int take_i = nums[i] + min(solve(nums,i+2,j) , solve(nums,i+1,j-1));
        int take_j = nums[j]  + min(solve(nums,i,j-2) , solve(nums,i+1,j-1));

        return t[i][j]=max(take_i , take_j);
    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        int total = accumulate(begin(nums) , end(nums) , 0);
        int alicescore = solve(nums,0,n-1);
        int bobscore = total-alicescore;
        return alicescore>bobscore;
        
    }
};