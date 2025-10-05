// Last updated: 10/5/2025, 8:52:39 AM
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = INT_MIN;
    for(int i=0 ; i<24 ; i++)
    {
        int count = 0 ;
        for(auto candidate : candidates)
        {
            if((candidate & (1<<i)) !=0)
            {
                count++;
            }
        }
        maxi = max(maxi,count);

    }
    return maxi;
     

    }
};