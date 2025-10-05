// Last updated: 10/5/2025, 8:56:58 AM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
    //    for(int i=0;i<strs.size();i++){
    //        sort(strs[i].begin(),strs[i].end());
    //    }
    int flag=0;
        for(int i=0;i<strs[0].size();i++){
            for(int j=0;j+1<strs.size();j++){
             if(int(strs[j][i])>int(strs[j+1][i])){
                   flag++;
                   break;
                  
               }
             
            }
             

                 
        }
        return flag;
        
    }
};