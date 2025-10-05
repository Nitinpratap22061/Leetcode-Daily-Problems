// Last updated: 10/5/2025, 8:58:37 AM
class Solution {
public:
    string reverseWords(string s) {

        int n=s.length();
        int i=0;
        int j;
        
        while(i<n){
            j=i;
        while( j<n && s[j]!=' '){
            j++;
        }
        int k=j-1;
        
        while(i<k){
            swap(s[i],s[k]);
            i++;
            k--;
        }
          
        i=j+1;
        }
        return s;
        
    }
};