// Last updated: 10/5/2025, 8:54:56 AM
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        int n=s.size();
        char arr[n];
        int j=0;
        for(int i=0;i<indices.size();i++)
        {
            int idx=indices[i];
            arr[idx]=s[j];
            j++;
        }
        for(int i=0;i<n;i++)
        {
          ans+=arr[i];
        }
        return ans;
        
    }
};