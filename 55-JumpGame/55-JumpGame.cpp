// Last updated: 10/5/2025, 9:02:15 AM
class Solution {
public:
    int t[10001];
    bool solve(vector<int>& nums , int idx)
    {
        int m = nums.size();
        if(idx == m-1 )
        {
            return true;
        }
        if(t[idx]!=-1)
        {
            return t[idx];
        }
        for(int i = 1 ; i<= nums[idx] ; i++)
        {
            
            if(solve(nums , i+idx)) return t[idx] = true;
        }
        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
       return solve(nums , 0 );
        
    }
};