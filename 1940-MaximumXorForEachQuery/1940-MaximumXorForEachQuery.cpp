// Last updated: 10/5/2025, 8:53:53 AM
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int XOR=0;
       int n = nums.size();
       vector<int>res(n);
        for(int i=0 ; i<n ; i++)
        {
            XOR ^=nums[i];
        }
        //flip to find best k
        int mask = (1<<maximumBit) - 1;
        for(int i=0 ; i<n ;i++)
    {
        int k = XOR ^ mask;
        res[i]=k;
        XOR ^= nums[n-i-1];
    }
    return res;

    }
};