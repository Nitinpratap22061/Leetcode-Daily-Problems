// Last updated: 10/5/2025, 8:53:04 AM
class Solution {
public:
       
    int numberOfBeams(vector<string>& bank) {
        int n =bank.size();
        int res =0 ;
        int prevdevice = 0;
        for(int i=0 ;i<n; i++)
        {
            int currdevice = 0;
            for(char &ch : bank[i])
            {
                if(ch=='1')
                {
                    currdevice++;
                }

            }
            res+=currdevice*prevdevice;
            if(currdevice!=0)
            {
                prevdevice = currdevice;
            }
        }
        return res;
        
    }
};