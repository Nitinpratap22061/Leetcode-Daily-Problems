// Last updated: 10/5/2025, 8:58:00 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        if(k<=1)
        {
            return 0;
        }
        int product=1;
        int j=0;
        int result=0;
        int n=nums.size();
        while(j<n)
        {
            product*=nums[j];
            while(product>=k)
            {
                product=product/nums[i];
                i++;
            }
            result +=(j-i+1);
            j++;
            
        }
        return result;
        
    }
};