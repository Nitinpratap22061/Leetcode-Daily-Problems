// Last updated: 10/5/2025, 8:52:57 AM
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3 ; 
        vector<long long>lsummin(N,0);
        vector<long long>rsummin(N,0) ; 
        priority_queue<int>pq ; 
        long long lsum =0 ;
        for(int i = 0 ; i<2*n ; i++)
        { 
             pq.push(nums[i]) ; 
             lsum +=nums[i] ; 

             if(pq.size()>n)
             {
                lsum-=pq.top() ; 
                pq.pop() ; 
             }
             lsummin[i] = lsum ;
        }
        long long rsum = 0 ; 
        priority_queue<int,vector<int>,greater<int>>pq1 ; 
        for(int i = 3*n-1 ; i>=n ; i--)
        {
            pq1.push(nums[i]) ; 
            rsum+=nums[i] ; 
            if(pq1.size() > n )
            {
                rsum-=pq1.top() ; 
                pq1.pop();
            }
            rsummin[i] = rsum ; 
        }

        long long res = LLONG_MAX ; 

        for(int i = n-1 ; i<=2*n-1 ; i++)
        {
            res = min(res , lsummin[i]-rsummin[i+1]);
        }

        return res ; 
        
    }
};