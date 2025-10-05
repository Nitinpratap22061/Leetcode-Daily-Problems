// Last updated: 10/5/2025, 8:50:14 AM
class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        for(int i=1 ; i<n ; i++)
        {
            num = num+1|x;
        }
        return num;
        
    }
};