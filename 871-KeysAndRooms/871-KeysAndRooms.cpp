// Last updated: 10/5/2025, 8:57:32 AM
class Solution {
public:
    void dfs(vector<vector<int>> & rooms,int u,vector<bool>& visited)
    {
        visited[u]=true;
        for(int &v:rooms[u])
        {
            if(!visited[v])
            {
                dfs(rooms,v,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
       vector<bool>visited(n,false);
       dfs(rooms,0,visited);
       for(bool x:visited)
       {
           if(x==false)
           {
               return false;
           }
       }
       return true;
    }
};