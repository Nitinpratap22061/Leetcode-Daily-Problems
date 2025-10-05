// Last updated: 10/5/2025, 8:48:58 AM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int sum = 0 ;
        
        for(auto ele:nums)
        {
            if(ele>0)
            {
                st.insert(ele) ; 
            }
        }
        for(auto ele:st)
        {
            sum+=ele;
        }
        if(st.empty())
        {
            return *max_element(begin(nums) , end(nums));
        }
        return sum ; 
    }
};