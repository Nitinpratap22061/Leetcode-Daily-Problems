// Last updated: 10/5/2025, 8:54:22 AM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() ; 
        int i = 0 ; 
        int j = 0 ; 
        int sum = 0 ; 
        int result = 0 ; 
        unordered_set<int>st ; 
        while(j<n)
        {
            if(!st.count(nums[j]))
            {
                sum+=nums[j] ; 
                result = max(result,sum) ; 
                st.insert(nums[j]);
                j++;
            }
            else //shrink 
            {
                while(i<n && st.count(nums[j]))
                {
                    sum-=nums[i] ; 
                    st.erase(nums[i]);
                    i++;
                }

            }


        }

        return result ; 


        
    }
};