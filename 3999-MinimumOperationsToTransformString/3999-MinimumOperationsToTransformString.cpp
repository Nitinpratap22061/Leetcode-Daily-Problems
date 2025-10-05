// Last updated: 10/5/2025, 8:48:12 AM
class Solution {
public:
    int minOperations(string s) {

        int lowest = 26 ; 
        for(auto &ch : s)
            {
                if(ch!='a')
                {
                int ele = ch-'a' ; 
                if(lowest>ele)
                {
                    lowest = ele ; 
                }
                }
            }

        return 26-lowest ; 
        


        
        
    }
};