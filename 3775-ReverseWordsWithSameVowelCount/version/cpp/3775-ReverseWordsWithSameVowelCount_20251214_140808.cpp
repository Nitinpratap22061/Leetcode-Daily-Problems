// Last updated: 12/14/2025, 2:08:08 PM
1class Solution {
2public:
3    long long minMoves(vector<int>& balance) {
4        long long sum = 0 ; 
5      
6        int culpritIdx = -1 ; 
7        int n =balance.size() ; 
8        for(int i = 0 ; i<n ; i++)
9        {
10            if(balance[i]<0)
11            {
12               culpritIdx = i ; 
13            }
14            sum+=balance[i] ; 
15        }
16        if(sum<0)
17        {
18            return -1 ; 
19        }
20        if(culpritIdx==-1)
21        {
22            return 0 ; 
23        }
24        int distance = 1 ;
25        long long moves = 0 ; 
26
27        while(balance[culpritIdx]<0)
28        {
29            int leftidx = (culpritIdx-distance+n)%n ; 
30           int rightidx = (culpritIdx+distance)%n ; 
31
32           long long leftVal = balance[leftidx] ; 
33           long long rightVal = balance[rightidx] ; 
34
35           long long total = leftVal+rightVal ; 
36           if(leftidx==rightidx)
37           {
38            total-=rightVal ; 
39           }
40           long long temp = min((long long)-balance[culpritIdx] , total) ; 
41           balance[culpritIdx]+=temp ; 
42           moves+= temp*distance ; 
43           distance++ ; 
44
45        }
46       return moves ; 
47
48        
49    }
50};