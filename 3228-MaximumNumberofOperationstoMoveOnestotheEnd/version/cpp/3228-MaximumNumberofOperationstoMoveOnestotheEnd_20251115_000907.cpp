// Last updated: 11/15/2025, 12:09:07 AM
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size() ; 
        int  i = 0 ; 
        int countone = 0 ; 
        int operation = 0 ; 
        while(i<n)
        {
            if(s[i]=='0')
            {
                operation+=countone ; 
                while(i<n && s[i]=='0')
                {
                    i++ ; 
                }
               
            }
             else
                {
                    countone++ ; 
                    i++ ; 
                }


        }

        return operation ; 


        
    }
};