// Last updated: 9/23/2025, 12:34:14 PM
class Solution {
public:

    vector<string>solve(string version)
    {
        vector<string>tokens ; 
        stringstream ss(version) ; 
        string token = "";
        while(getline(ss,token,'.'))
        {
            tokens.push_back(token) ; 
        }
        return tokens ; 
    }
    int compareVersion(string version1, string version2) {
        
        
        vector<string>v1 = solve(version1) ; 
        vector<string>v2 = solve(version2) ; 
        int n = v1.size() ; 
        int m = v2.size() ; 
        int i = 0 ; 
        while(i<n || i<m)
        {
            int a = i<n?stoi(v1[i]):0 ; 
            int b = i<m?stoi(v2[i]):0 ; 

            if(a<b)
            {
                return -1 ; 
            }
            else if(a>b)
            {
                return 1 ; 
            }
            else
            {
                i++ ; 
            }
        }


        return 0 ; 



        
    }
};