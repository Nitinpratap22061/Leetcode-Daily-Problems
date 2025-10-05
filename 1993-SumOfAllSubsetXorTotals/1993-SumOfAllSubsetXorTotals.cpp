// Last updated: 10/5/2025, 8:53:49 AM
class Solution {
public:
    void solve(vector<int>& nums , int i , vector<vector<int>>& subset , vector<int>& ans)
    {
        if(i==nums.size())
        {
            subset.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        solve(nums,i+1,subset,ans);
        ans.pop_back();
        solve(nums,i+1,subset,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>ans;
        solve(nums , 0 , subset,ans);
        int res = 0 ;
        for(auto &vec:subset)
        {
            int Xor = 0 ;
            for(int &num : vec)
            {
                Xor ^=num;
            }
            res+=Xor;
        }
        return res;

        
    }
};