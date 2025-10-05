// Last updated: 10/5/2025, 9:00:49 AM
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        int j;
        string result="";
        string ans;
        while(i<n){
        while(i<n && s[i]==' '){
            i++;
        }
        if(i>=n)break;
        j=i+1;
        while(j<n && s[j]!=' '){
            j++;
        }
        ans=s.substr(i,j-i);
        if(result==""){
            result=ans;
        }
        else{
            result=ans+" "+result;
        }
       i=j+1;
        }
         return result;

}

};