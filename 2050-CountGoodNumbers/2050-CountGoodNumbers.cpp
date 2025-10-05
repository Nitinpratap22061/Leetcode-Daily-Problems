// Last updated: 10/5/2025, 8:53:38 AM
class Solution {
public:
const int MOD = 1e9+7;
     int fastexpo(long long a , long long b)
     {
        if(b==0) return 1 ;
        long long half = fastexpo(a,b/2);
        long long res = (half*half)%MOD;
        if(b%2==1)
        {
            res = (res*a)%MOD;
        }
        return res;
     }
    int countGoodNumbers(long long n) {
        return (long long)fastexpo(5,(n+1)/2) * fastexpo(4,n/2) %MOD;
    

        
    }
};