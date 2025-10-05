// Last updated: 10/5/2025, 8:53:52 AM
class Solution {
public:
   int solve(int n , int k )
   {
    if(n==1)
    {
        return 0 ; 
    }
    int idx = solve(n-1 , k) ; 
    idx=(idx+k)%n;
    return idx;
   }
    int findTheWinner(int n, int k) {
       // brute force solution --- 0(n^2);
        // vector<int> simulation;
        // for (int i = 1; i <= n; i++) {
        //     simulation.push_back(i);  
        // }

        // int i = 0;
        // while (simulation.size() > 1) {
        //     int idx = (i + k - 1) % simulation.size(); 
        //     simulation.erase(simulation.begin() + idx); 
        //     i = idx ;  
        // }

        // return simulation[0]; 
        int ans =  solve(n , k)  ; 
        return ans+1;
    }
};
