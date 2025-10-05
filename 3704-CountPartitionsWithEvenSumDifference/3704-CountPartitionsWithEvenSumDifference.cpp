// Last updated: 10/5/2025, 8:49:20 AM


class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> helper; 
        int count = 0;
        int leftsum = 0; 

        for (int i = 0; i < nums.size(); i++) {
            helper.push_back(nums[i]);
            leftsum += nums[i]; 
            int rightsum = totalsum - leftsum; 

            if ((leftsum - rightsum) % 2 == 0) { 
                count++;
            }
        }
        if(count!=0) return count-1;
        return 0;
    }
};
