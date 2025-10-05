// Last updated: 10/5/2025, 9:01:05 AM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalkamai = accumulate(begin(gas) , end(gas) , 0);
        int totalkharch = accumulate(begin(cost) , end(cost) ,0);

        if(totalkamai < totalkharch)
        {
            return -1 ; 
        }
        int total = 0 ;
        int res = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            total = total + gas[i] - cost[i] ; 
            if(total<0)
            {
                total = 0 ;
                res = i+1 ;
            }

        }
        return res;
        
    }
};