// Last updated: 10/5/2025, 8:52:41 AM
class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        char maxchar=' ';
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]){//3 length ka unique substring k liye
                maxchar=max(maxchar,num[i]);
            }
        }
        if(maxchar==' '){
            return "";
        }
        return string(3,maxchar);
      
      

        
    }
};