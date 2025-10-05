// Last updated: 10/5/2025, 8:50:00 AM
class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0 ; 
        for(auto ele :s)
        {
            if(ele=='a'||ele=='e'||ele=='i'||ele=='o'||ele=='u')
            {
                count++;
            }
        }
        if(count==0)
        {
            return false ; 
        }
        return true ; 
        
    }
};