// Last updated: 10/5/2025, 8:54:36 AM
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() ; 
        vector<int>res(n,0);
        if(k==0) return res;
        int i = -1 , j = -1;
        if(k>0)
        {
            i=1 ; 
            j=k;
        }
        else
        {
            i = n-abs(k);
            j=n-1;
        }
        int windowsum = 0 ;
        for(int pointer = i ; pointer<=j ; pointer++)
        {
            windowsum+=code[pointer];

        }
        for(k = 0 ; k<n ; k++)
        {
            res[k] = windowsum ; 
            windowsum -=code[i%n];
            i++;
            windowsum +=code[(j+1)%n];
            j++;
        }

        return res;
        
    }
};