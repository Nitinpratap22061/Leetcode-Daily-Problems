// Last updated: 10/5/2025, 8:55:37 AM
class Solution {
public:
    int maximum69Number (int num) {

        string ans = to_string(num) ; 

        //aim : - largest banana by 1 swap 
        for(int i = 0 ; i<ans.size() ; i++)
        {
            if(ans[i]=='6')
            {
                ans[i]='9' ; 
                break ; 
            }
        }

        int helper = stoi(ans) ; 

        return helper ; 


        
    }
};