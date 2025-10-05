// Last updated: 10/5/2025, 8:52:49 AM
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum = 0 ;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        double target = sum/2;
        int cnt = 0 ; 
        while(sum>target)
        {
            cnt++;
            double highest = pq.top();
            pq.pop();
            sum -=highest ;
            highest = highest/2;
            sum+=highest;
            pq.push(highest);

        }
        return cnt;
        
    }
};