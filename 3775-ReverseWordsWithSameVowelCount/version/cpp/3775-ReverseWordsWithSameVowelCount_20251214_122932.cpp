// Last updated: 12/14/2025, 12:29:32 PM
1class Solution {
2public:
3
4     bool isVowel(char c)
5     {
6          return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
7     }
8    string reverseWords(string s) {
9
10        vector<string>mid ; 
11        string helper ; 
12        stringstream ss(s) ; 
13        while(ss>>helper)
14        {
15            mid.push_back(helper) ; 
16        }
17     
18        int count = 0 ; 
19        for(int i = 0 ; i<mid[0].length() ; i++)
20        {
21            char ch = mid[0][i] ; 
22            if(isVowel(ch))
23            {
24                count++ ; 
25            }
26        }
27        string result ;
28
29        for(int i = 1 ; i<mid.size();i++)
30        {
31            int fcount = 0 ;
32            string mila = mid[i];
33            for(int j =0 ; j<mila.length();j++)
34            {
35                if(isVowel(mila[j]))
36                {
37                    fcount++ ;
38                }
39            }
40            if(fcount==count)
41            {
42                reverse(begin(mila),end(mila));
43                mid[i]= mila;
44               
45            }
46            
47        }
48        for (int i = 0; i < mid.size(); i++) {
49            if (i > 0) result += " ";
50            result += mid[i];
51        }
52        return result ; 
53        
54    }
55};