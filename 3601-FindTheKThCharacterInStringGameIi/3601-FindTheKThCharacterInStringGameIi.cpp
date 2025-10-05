// Last updated: 10/5/2025, 8:49:41 AM
class Solution {
public:
    
    char kthCharacter(long long k, vector<int>& operations) {
        long long len =1 ; 
        long long newk = -1 ; 
        int optype = -1 ; 
        int n = operations.size() ; 

        if(k==1)
        {
            return 'a';
        }


        for(int i = 0 ; i<n ; i++)
        {
            len*=2 ; 
            if(len>=k)
            {
                optype =  operations[i] ; 
                newk = k - (len/2);
                break ;
            }
        }
        char ch =  kthCharacter(newk , operations) ; 

        if(optype==0)
        {
            return ch ; 

        }
        return (ch == 'z') ? 'a' : ch + 1;

    }
};