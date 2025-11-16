// Last updated: 11/16/2025, 11:16:24 AM
class Solution {
public:
    int minLengthAfterRemovals(string s) {

        int count_a = 0 ;
        int count_b = 0 ;

        for(auto &ch:s)
        {
            if(ch=='a')
            {
                count_a++;
            }
            else
            {
                count_b++;
            }

        }

        return abs(count_a - count_b);
        
    }
};