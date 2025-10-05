// Last updated: 10/5/2025, 8:53:02 AM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0 ; //a[0];
        int maxval = 0 ;
        int minval = 0 ;
        for(int &d : differences)
        {
            curr = curr+d;
            maxval = max(maxval,curr);
            minval = min(minval , curr);
            if((upper-maxval)-(lower-minval)+1 <=0)
            {
                return 0 ; 
            }
        }
        return (upper-maxval)-(lower-minval)+1;
        
    }
};