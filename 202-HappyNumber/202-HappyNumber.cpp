// Last updated: 10/5/2025, 9:00:28 AM
class Solution {
public:
    bool isHappy(int n) {
        bool isHappy=false;
        unordered_set<int>seen;
        while(n!=1)
        {
            if(seen.find(n)!=seen.end())
            {
                return false;
            }
            seen.insert(n);
           string s=to_string(n);
           int sum=0;
           for(int i=0 ; i<s.size() ;i++)
           {
              int num = s[i]-'0';
              sum = sum+(num*num);
           }
           n = sum;

        }
       return true;
    }
};