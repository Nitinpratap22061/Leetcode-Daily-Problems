// Last updated: 10/5/2025, 8:56:16 AM
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size=arr.size();
       int max=INT_MIN;
       int ans;
       for(int i=0;i<size;i++){
           if(arr[i]>max){
               max=arr[i];
           }
       }
        vector<int>freq(max+1,0);
        for(int i=0;i<size;i++){
            freq[arr[i]]++;
         }
         for(int i=0;i<freq.size();i++){
             if(freq[i]>(size/4)){
                ans=i;
                break;
              
             }
         }
         return ans;

        
    }
};