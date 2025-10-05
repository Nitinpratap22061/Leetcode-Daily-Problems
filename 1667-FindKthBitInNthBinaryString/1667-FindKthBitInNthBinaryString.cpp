// Last updated: 10/5/2025, 8:54:50 AM
class Solution {
public:
    char findKthBit(int n, int k) {
        int len = pow(2,n)-1;
        if(n==1)
        {
            return '0';
        }

        if(k<ceil(len/2.0))
        {
           return findKthBit(n-1 ,k);
        }
        else if(k==ceil(len/2.0))
        {
            return '1';
        }
        else
        {
            char ch = findKthBit(n-1 , len-(k-1));
            return (ch=='0') ? '1' : '0' ;
        }
        
        
    }
};