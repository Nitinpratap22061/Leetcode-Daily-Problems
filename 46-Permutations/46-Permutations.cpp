// Last updated: 10/5/2025, 9:02:22 AM
class Solution {
public:
void solve(vector<int>& nums , int k , vector<int>& temp ,  vector<vector<int>>&res , vector<bool>& used )
{
    if(k == 0)
    {
        res.push_back(temp);
        return;
    }
    for(int i = 0 ; i<nums.size() ; i++)
    {
        if(used[i]) continue;
        temp.push_back(nums[i]);
        used[i] = true;
        solve(nums , k-1 , temp , res ,used);
        temp.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int k = nums.size();
        vector<bool>used(k , false);
        vector<int>temp;
        vector<vector<int>>res;
        solve(nums , k , temp ,res , used);
        return res;
    }
};