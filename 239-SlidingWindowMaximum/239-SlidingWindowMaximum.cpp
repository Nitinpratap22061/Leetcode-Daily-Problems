// Last updated: 10/5/2025, 9:00:04 AM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int>res ; 
        deque<int>dq;
        for(int i = 0 ; i<n ; i++)
        {
            //step1--shrink 
            while(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            //step2-->codn according pop
            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            //step3-->push
            dq.push_back(i);

            //step--4 ans
            if(i>=k-1) // naya window bna
            {
                res.push_back(nums[dq.front()]);
            }
            

        }
        return res;
        
    }
};