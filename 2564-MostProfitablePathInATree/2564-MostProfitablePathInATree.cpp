// Last updated: 10/5/2025, 8:51:54 AM
class Solution {
public:
unordered_map<int,vector<int>>adj;
unordered_map<int,int>bobTime;
int maxIncome = INT_MIN;

bool dfsBob(int curr , int time , vector<bool>& visited)
{
    visited[curr] = true;
    bobTime[curr] = time ; 
    if(curr == 0)
    {
        return true;
    }
    for(auto &ngbr : adj[curr])
    {
        if(!visited[ngbr])
        {
           if( dfsBob(ngbr,time+1,visited) )
           {
            return true;
           }
        }
    }
    bobTime.erase(curr);
    return false;
}
void dfsAlice(int curr , int time , int income , vector<bool>& visited , vector<int>& amount )
{
    visited[curr] = true ; 
    if(bobTime.find(curr) == bobTime.end() || time<bobTime[curr])
    {
        income+=amount[curr];
    }
    else if(time == bobTime[curr])
    {
        income +=amount[curr]/2;
    }
    //leaf 
    if(adj[curr].size()==1 && curr!=0)
    {
        maxIncome = max(maxIncome , income);
    }
    for(auto &ngbr : adj[curr])
    {
        if(!visited[ngbr])
        {
            dfsAlice(ngbr , time+1 , income,visited,amount);
        }
    }
}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //graph bnao
        int n = edges.size()+1;
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time = 0 ;
        vector<bool>visited(n,false);
        dfsBob(bob,time,visited);
        int income = 0 ;
        visited.assign(n,false);
        dfsAlice(0,0,income,visited,amount);

        return maxIncome;

        
    }
};