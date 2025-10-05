// Last updated: 10/5/2025, 8:58:54 AM
class Solution {
public:
    int solve(vector<int>& nums , int i , int j)
    {
        if(i>j) return 0;
        if(i==j) return nums[i] ;
        int take_i = nums[i] + min((solve(nums,i+2,j)) , (solve(nums,i+1 , j-1)));
        int take_j = nums[j] + min(solve(nums,i+1 , j-1) , solve(nums,i,j-2));

        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size() ;
        int p1score = solve(nums,0,n-1);
        int totalscore = accumulate(begin(nums),end(nums) , 0);
        int p2score = totalscore - p1score ; 
        return p1score>=p2score;
        
    }
};