// Last updated: 12/9/2025, 12:45:09 PM
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
11
12        for(auto &box : boxTypes)
13        {
14            if(truckSize==0)
15            {
16                break ; 
17            }
18            int take = min(box[0] , truckSize) ; 
19            total += take*box[1] ; 
20            truckSize -= take ; 
21        }
22
23         return total ; 
24
25        
26
27
28      
29        
30    }
31};