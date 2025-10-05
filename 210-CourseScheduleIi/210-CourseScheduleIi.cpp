// Last updated: 10/5/2025, 9:00:21 AM
class Solution {
public:
bool hascycle =false;
void dfs(unordered_map<int,vector<int>>&adj , int u , vector<bool>& visited ,stack<int>&st , vector<bool>& inrecc)
{
    visited[u] = true ; 
    inrecc[u] = true;
    for(int &v:adj[u])
    {
        if(!visited[v])
        {
            dfs(adj,v,visited,st,inrecc);
        }
        else if(inrecc[v])
        {
            hascycle = true;
            return;
        }
    }
    inrecc[u]=false;
    st.push(u);
    return;

    
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj ; 
        for(auto &vec :  prerequisites)
        {
            int u = vec[0] ; 
            int v = vec[1] ;
            adj[v].push_back(u) ; 
        }
        //simple have to do topo sort --->dfs easy
        stack<int>st ; 
        int n = numCourses;
        vector<bool>inrecc(n,false);
        vector<bool>visited(n,false);
        for(int i=0 ; i<n ; i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited,st,inrecc);
                if(hascycle)
                {
                    return {};
                }
            }
        }
        vector<int>res;
        vector<int>empty;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;

        
    }
};