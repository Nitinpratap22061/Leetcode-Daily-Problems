// Last updated: 10/5/2025, 8:48:51 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int first = abs(z-x);
        int second = abs(z-y) ;
        if(first>second)
        {
            return 2;
        }
        else if(first<second)
        {
            return 1;
        }
        return 0;
        
    }
};