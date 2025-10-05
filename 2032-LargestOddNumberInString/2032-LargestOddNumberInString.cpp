// Last updated: 10/5/2025, 8:53:42 AM
#include <iostream>

class Solution {
public:
    string largestOddNumber(string num) {
        //  int ans=stoi(num);
        // if(ans%2!=0){
        //     return to_string(ans);
        // }
        int n = num.size();
        int lastOddIndex = -1;

        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';

            if (digit % 2 != 0) {
                lastOddIndex = i;
                break;
            }
        }

        if (lastOddIndex == -1) {
            return "";  // No odd digits found
        }

        return num.substr(0, lastOddIndex + 1);
    }
};
