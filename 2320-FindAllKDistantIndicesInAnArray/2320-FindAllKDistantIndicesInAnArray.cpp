// Last updated: 10/5/2025, 8:52:47 AM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();
        set<int>ans ;
        vector<int> target;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                target.push_back(i);
            }
        }
        for (auto ele : target) {
            for (int i = 0; i < n; i++) {
                if (abs(i - ele) <= k) {
                   ans.insert(i) ; 
                }
            }
        }
        vector<int>res;
        for(auto ele:ans)
        {
            res.push_back(ele);
        } 
        return res ; 
    }
};