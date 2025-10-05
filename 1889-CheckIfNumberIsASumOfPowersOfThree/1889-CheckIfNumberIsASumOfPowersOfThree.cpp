// Last updated: 10/5/2025, 8:54:05 AM
class Solution {
public:

string toBase3(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += to_string(n % 3);  
        n /= 3;                  
    }
    reverse(res.begin(), res.end()); 
    return res;
}
    bool checkPowersOfThree(int n) {

        string a = toBase3(n) ; 
         for(int i =  0 ; i<a.length() ; i++)
         {
            if(a[i]-'0' >=2)
            {
                return false; 
            }
         }
         return true ; 
        
    }
};