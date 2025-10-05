// Last updated: 10/5/2025, 8:50:16 AM
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0 ; i+1<s.size();i++)
        {
            char ch1 = s[i];
            char ch2 = s[i+1];
            int ans1 = int(ch1);
            int ans2 = int(ch2);
            int diff = abs(ans1-ans2);
            sum = sum+diff;
        }
          return sum;
    }
};