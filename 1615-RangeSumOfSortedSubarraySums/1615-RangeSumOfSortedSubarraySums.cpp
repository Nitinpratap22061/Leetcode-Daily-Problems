// Last updated: 10/5/2025, 8:55:04 AM
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>res;
        int fans=0;
        int sum=0;
        for(int i=0;i<nums.size() ; i++)
        {
            for(int j=i;j<nums.size() ;j++)
            {
                sum = sum + nums[j];
                res.push_back(sum);

            }
            sum=0;
        }
        sort(res.begin() , res.end());
        const int mod = 1e9 + 7;
        for(int i = left-1 ; i<right ; i++)
        {
            fans=(fans+res[i])%mod;
        }
        return fans;
        
    }
};