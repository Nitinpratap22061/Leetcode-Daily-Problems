// Last updated: 10/5/2025, 8:57:23 AM
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int,vector<int>>pq ; 
        int n = stations.size() ; 
        int cd = startFuel ; 
        int i = 0 ; 
        int ans = 0 ; 
        while(cd<target)
        {
            while(i<n && stations[i][0]<=cd)  // tabhi fuel rakh skta 
            {
                pq.push(stations[i][1]);
                i++;
            }
             
           if(pq.empty()) return -1 ; 

            //bhai refill krana parega 
            cd += pq.top() ; 
            pq.pop() ; 
            ans++;

        }
        return ans ; 
       
    }
};
