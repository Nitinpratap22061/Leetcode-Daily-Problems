// Last updated: 10/25/2025, 9:13:52 PM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {

        // like saare nums 1 ke i or nums 2 kme i jaahan tk hai wahan diff l=niaklo uso diff + krte jao uthne opp to lagenge hi pr last me jo ele bacheaga  unums2 suska nums2 me hi uske near element nikao - that utna ioern phir lagega and +1 to lageag hi appen

        int n = nums1.size() ; 
        long long cost = 0 ; 
        for(int i = 0 ; i<n ; i++)
            {
                cost += abs(nums1[i]-nums2[i]) ; 
            }

           int target = nums2[n] ; 

        long long extra = LLONG_MAX; 

        for(int i = 0 ; i<n ; i++)
            {
                long long low = min(nums1[i] , nums2[i]) ; 
                long long high = max(nums1[i] , nums2[i]) ; 

                long long helpercost = 0 ; 

                if(target<low) 
                {
                    helpercost = low-target ; 
                 }
                else if(target>high)
                {
                    helpercost = target-high ; 
                }
                else
                {
                    helpercost  = 0 ; 
                }
                long long costy = helpercost+1 ; 
                extra = min(extra , costy) ; 
            }
        return cost+extra ; 
        
        
    }
};