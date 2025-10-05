// Last updated: 10/5/2025, 8:59:28 AM
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int a=10;
        int c=9;
        
        if(n==0)return 1;
        for(int i=2;i<=n;i++){
           c*=(11-i);
           a+=c;
        }
        return a;
    }
};