// Last updated: 10/5/2025, 8:50:47 AM
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);


        unordered_map<int,vector<int>>mp;

        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            indegree[v]+=1;
        }
        int count  = 0 ;
        int ans;
        for(int i = 0 ; i<n ; i++)
        {
            if(indegree[i]==0)
            {
                count++;
                ans = i;

            }
        }
        if(count>1)
        {
            return -1;
        }
        return ans;
        
        
    }
};