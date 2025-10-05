// Last updated: 10/5/2025, 9:02:56 AM
class Solution {
public:
    bool isPalindrome(int x) {
        string result;
        result= to_string(x);
    int i=0;
    int j=result.size()-1;

    while(i<j){
        if(result[i]!=result[j]){
            return false;
            break;
        }
        i++;
        j--;
    }
    return true;
        
    }
};