// Last updated: 10/5/2025, 8:51:55 AM
class Solution {
public:
    int z  ; 
    int l , h, o ;
    int t[100001];
    const int MOD = 1e9 + 7;
    int solve(int length)
    {
        if(length > h)
        {
            return 0 ;
        }
        if(t[length]!=-1)
        {
            return t[length] ; 
        }
        bool addone = false ;
        if(length>= l && length <= h)
        {
            addone = true ;

        }
        int append_zero = solve(length+z);
        int append_one = solve(length+o);

        return  t[length] = (addone + append_zero + append_one)%MOD;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        z = zero ;
        o = one;
        h=high ;
        l = low ; 
        memset(t,-1,sizeof(t));
        return solve(0);

        
    }
};