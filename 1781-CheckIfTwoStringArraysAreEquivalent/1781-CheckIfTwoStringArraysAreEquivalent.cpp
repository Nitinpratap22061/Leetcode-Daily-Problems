// Last updated: 10/5/2025, 8:54:30 AM
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s="";
        string s1="";

        for(int i=0;i<word1.size();i++){
            s=s+word1[i];
        }
        for(int i=0;i<word2.size();i++){
            s1=s1+word2[i];
        }
        if(s==s1){
            return true;
        }
        else{
            return false;
        }
    
        
    }
};