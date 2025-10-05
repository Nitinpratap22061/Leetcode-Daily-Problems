// Last updated: 10/5/2025, 8:53:29 AM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
bool checkPath(unordered_map<int , vector<int>>&mp , int source , int destination , vector<bool>&visited)
{
    if(source==destination)
    {
        return true;
    }
    visited[source] = true;
    // nhi to adjecent ko explore kro
    for(auto &v:mp[source])
    {
         if(!visited[v])
         {
            
            if(checkPath(mp,v,destination,visited))
            {
                return true;
            }

         }
    }
    return false;
}
   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //graph bnao
        
        unordered_map<int , vector<int>>mp;
        vector<bool>visited(n,false);
        for(auto ele :edges)
        {
            int u=ele[0];
            int v=ele[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(mp.empty())
        {
            return true;
        }
        
            return checkPath(mp,source,destination,visited);
            
            
            
        
       

        
    }
};

