// Last updated: 10/5/2025, 8:56:47 AM
class Solution {
public:
      int n;
      int t[366];
      int solve(vector<int>& days , int index , vector<int>& cost)
      {
        int j;
        if(index>=n) return 0;
        if(t[index]!=-1)
        {
            return t[index];
        }
        //explore option
       int  cost_1_day = cost[0] + solve(days,index+1 , cost);
        int maxDay = days[index]+7 ;
        j=index;
        while(j<n && days[j]<maxDay)
        {
            j++;
        }
        int cost_7_day = cost[1] + solve(days , j , cost) ;
        j = index ;
        maxDay = days[index]+30;
         while(j<n && days[j]<maxDay)
        {
            j++;
        }
        int cost_30_day = cost[2] + solve(days,j , cost);
        return t[index] =  min({cost_1_day , cost_7_day , cost_30_day});
      }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(t,-1,sizeof(t));
        return solve(days , 0, costs);
        
    }
};