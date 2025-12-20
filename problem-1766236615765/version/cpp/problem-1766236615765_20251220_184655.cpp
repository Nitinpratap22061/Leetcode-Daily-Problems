// Last updated: 12/20/2025, 6:46:55 PM
1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        long long count =1 ; 
5        long long res = 1 ; 
6        for(int i = 1 ; i<prices.size() ; i++)
7        {
8            if(prices[i-1]-prices[i]==1){
9                count++ ; 
10            }
11            else
12            {
13                count =1 ; 
14            }
15            res+=count ; 
16        }
17        return res ; 
18        
19    }
20};