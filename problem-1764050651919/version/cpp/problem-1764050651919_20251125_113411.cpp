// Last updated: 11/25/2025, 11:34:11 AM
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if(k % 2 == 0 || k % 5 == 0) return -1;

        long long num = 1;
        int len = 1;

        while(true)
        {
            if(num % k == 0)
            {
                return len;
            }

            num = (num * 10 + 1) % k;   
            len++;
        }

        return -1;
    }
};
