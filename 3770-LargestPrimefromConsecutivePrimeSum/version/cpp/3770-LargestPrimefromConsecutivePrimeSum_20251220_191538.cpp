// Last updated: 12/20/2025, 7:15:38 PM
1class Solution {
2public:
3
4   vector<bool>sieve(int n)
5   {
6    vector<int>res ; 
7    vector<bool>isPrime(n+1 , true) ; 
8    isPrime[0] = false ; 
9    isPrime[1] = false ; 
10
11    for(int i = 2 ; i*i<=n ; i++)
12    {
13        if(isPrime[i])
14        {
15            for(int j = i*i ; j<=n ; j+=i)
16            {
17                isPrime[j] = false ; 
18            }
19        }
20    }
21
22    
23    return isPrime ; 
24
25   }
26     
27    int largestPrime(int n) {
28
29         vector<bool> isPrime = sieve(n);
30
31         //compute consecutive sum 
32         int sum = 0 ; 
33         int ans = 0 ; 
34         for(int i=2 ; i<= n ; i++)
35         {
36            if(isPrime[i])
37            {
38                sum+=i ; 
39                if(sum>n) break ; 
40
41                if(isPrime[sum])
42                {
43                    ans = sum ; 
44                }
45            }
46             
47         }
48        return ans ; 
49    }
50};