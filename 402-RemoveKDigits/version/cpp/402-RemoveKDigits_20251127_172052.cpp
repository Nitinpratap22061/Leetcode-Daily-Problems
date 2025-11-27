// Last updated: 11/27/2025, 5:20:52 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        int n = num.size();
5        string res = "";
6        res += num[0];
7        for(int i = 1; i < n; i++){
8            while(res.size() && k && res[res.size() -1] > num[i]){
9                res.pop_back();
10                k--;
11            }
12            if(!res.size() && num[i] == '0') continue;
13            res.push_back(num[i]);
14        }
15        while(k && res.size()){ //why ? eg: num == 112 & k = 1
16            k--;
17            res.pop_back();
18        }
19        return res.size() == 0 ? "0" : res;
20    }
21};