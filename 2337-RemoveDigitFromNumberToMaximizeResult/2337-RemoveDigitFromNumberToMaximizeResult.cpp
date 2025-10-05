// Last updated: 10/5/2025, 8:52:44 AM
class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans ;
        int help = INT_MIN;
        int res;
        for(int i=0 ; i<number.size();i++)
        {
            char ch = number[i];
            if(ch == digit && digit < number[i+1] )
            {

               number.erase(i,1);
               return number;
                
            }
        }
        int last = number.find_last_of(digit);
        number.erase(last,1);
        return number;

    }
};