// Last updated: 10/5/2025, 8:49:36 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto ele : nums)
        {
            if(ele<k)
            {
                return -1;
            }
            else if(ele>k)
            {
            st.insert(ele) ;
            } 
        }
        return st.size();
        
    }
};