// Last updated: 10/5/2025, 8:48:10 AM
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {

        int n = nums.size() ; 

        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        // ngl
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();


        //ngr
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0 ;
        for(int i = 0 ; i<n ; i++)
            {
                if(left[i]!=-1 && i-left[i]>=2)
                {
                    ans++ ; 
                }
                if(right[i]!=n && right[i]-i>=2)
                {
                    ans++ ; 
                }
            }

        return ans ; 
    }
};