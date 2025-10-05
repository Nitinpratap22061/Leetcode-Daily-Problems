// Last updated: 10/5/2025, 9:00:29 AM
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int sc = 0 ; 
        while(left!=right)
        {
            left=left>>1 ; 
            right=right>>1;
            sc++;
        }
        return left<<sc;
        
    }
};