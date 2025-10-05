// Last updated: 10/5/2025, 8:57:43 AM
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        
       
        if (n != goal.size())
            return false;
        
        
        s += s;
        
       
        if (s.find(goal) != string::npos)
            return true;
        
        return false;
    }
};
