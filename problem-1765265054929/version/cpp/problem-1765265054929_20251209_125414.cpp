// Last updated: 12/9/2025, 12:54:14 PM
1class Solution {
2public:
3    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
4        sort(boxTypes.begin() , boxTypes.end() , 
5        [](auto &a , auto &b)
6        {
7            return a[1] > b[1] ; 
8        } ) ; 
9
10        int total = 0 ; 
11        int remaining = truckSize ; 
12        int last = -1 ; 
13        for(auto &box : boxTypes)
14        {
15          if(box[0]<=remaining)
16          {
17            total+=box[1]*box[0] ; 
18            remaining -= box[0] ; 
19          }
20          else
21          {
22            total += remaining*box[1] ; 
23            break ; 
24          }
25        }
26        
27
28         return total ; 
29
30        
31
32
33      
34        
35    }
36};