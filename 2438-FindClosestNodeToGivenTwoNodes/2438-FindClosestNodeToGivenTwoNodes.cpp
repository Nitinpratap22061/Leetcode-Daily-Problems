// Last updated: 10/5/2025, 8:52:18 AM
class Solution {
public:
    void dfs( unordered_map<int,vector<int>>& mp , int node , vector<int>& dist , int n,vector<bool>& visited,int distance)
    {
        visited[node]=true;
        dist[node]=distance;
        for(auto &ngbr:mp[node])
        {
            if(ngbr!=-1 && !visited[ngbr])
            {
                distance+=1;
                dfs(mp,ngbr,dist,n,visited,distance+1);

            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        unordered_map<int,vector<int>>mp;
        for(int i=0 ; i<n ; i++)
        {
           mp[i].push_back(edges[i]); 
        }

        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);
        
       
        dfs(mp,node1,dist1,n,visited1,0);
        dfs(mp,node2,dist2,n,visited2,0);
        int minimization=INT_MAX;
        int target=-1;
        

        for(int i=0 ; i<n ; i++)
        {
            int maxd = max(dist1[i],dist2[i]);

            if(minimization>maxd)
            {
                minimization = maxd;
                target = i  ;

            }

        }

        return target;



        
    }
};