// Last updated: 10/5/2025, 9:02:51 AM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s;
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                break;
            }
            else{
                s.push_back(strs[0][i]);
            }
        }
        return s;
        


        
    }
};