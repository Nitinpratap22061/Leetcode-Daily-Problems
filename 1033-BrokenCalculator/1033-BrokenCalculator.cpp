// Last updated: 10/5/2025, 8:56:44 AM
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0 ;
        if(startValue == target)
        {
            return ans ;
        }
        if(startValue>target)
        {
            return startValue - target ; 
        }
        if(target %2 == 0)
        {
            return 1 + brokenCalc(startValue , target/2);
        }
        return 1+brokenCalc(startValue , target+1);
        
    }
};