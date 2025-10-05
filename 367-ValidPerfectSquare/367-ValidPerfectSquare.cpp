// Last updated: 10/5/2025, 8:59:26 AM
class Solution {
public:
    bool isPerfectSquare(int num) {
         if (num < 2) {
            return true;
        }
    

        long long start=0;
        long long end =num/2;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(mid*mid==num){
                return true;
            }
            else if (mid*mid<num){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
        
    }
};