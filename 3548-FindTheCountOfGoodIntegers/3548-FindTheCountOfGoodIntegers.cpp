// Last updated: 10/5/2025, 8:49:46 AM
class Solution {
public:


   int factorial(int num)
   {
     if(num<=1)
     {
        return 1 ;
     }
     return num*factorial(num-1);
   }
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>st;
        int d = (n+1)/2;
        int start = pow(10,d-1);
        int end = pow(10,d)-1;

        for(int num = start ; num<=end ; num++)
        {
            string left = to_string(num);
            string full = "";
            if(n%2==0)
            {
                string right = left ;
                reverse(right.begin() , right.end());
                full = left+right;
            }
            else
            {
                string right = left.substr(0,d-1);
                reverse(right.begin(),right.end());
                full = left+right;
            }
            //palindrome bn gya now check k div
            long long number = stoll(full);
            if(number%k!=0) continue;
            sort(full.begin() , full.end());
            st.insert(full);

        }
        //permutn calc for each
        long long res = 0 ;
        for(auto string : st)
        {
            vector<int>count(10,0);
            for(auto ch:string)
            {
                count[ch-'0']++;
            }
            //leading zero avoid
            int total = string.length();
            int zero = count[0];
            int nonzero = total-zero;

            long long perm = nonzero * factorial(total-1);

            for(int i = 0 ; i<10;i++)
            {
                perm/=factorial(count[i]);
            }
            res+=perm;
        }
        return res;
    }
};