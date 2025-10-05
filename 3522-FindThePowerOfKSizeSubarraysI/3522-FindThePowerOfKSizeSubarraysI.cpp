// Last updated: 10/5/2025, 8:49:50 AM
class Solution {
public:
    bool isSorted(vector<int>& vec)
    {
        for(int i=1 ; i<vec.size() ; i++)
        {
            if(vec[i]!=vec[i-1]+1)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<vector<int>>res;
        int n = nums.size();
        int i = 0 ; 
        int j = 0 ; 
        vector<int>ans;
        while(j<n)
        {
            ans.push_back(nums[j]);
            if(j-i+1 == k )
            {
                res.push_back(ans);
                ans.erase(ans.begin());
                i++;
            }
            j++;
        }
        vector<int>fans;

        for(auto &vec : res)
        {
            if(isSorted(vec))
            {
                fans.push_back(vec.back());
            }
            else
            {
                fans.push_back(-1);
            }
        }
        return fans;
        
    }
};