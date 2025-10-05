// Last updated: 10/5/2025, 8:50:43 AM
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long mini = max(0,n-(2*(limit)));
        long long maxi = min(n,limit);

        long long ways = 0 ;

        for(int i = mini ; i<=maxi ; i++)
        {
            int N = n-i;
            int minimum = max(N-limit,0);
            int maximum = min(N,limit);

            ways+=(maximum-minimum+1);


        }

        return ways;
        
    }
};