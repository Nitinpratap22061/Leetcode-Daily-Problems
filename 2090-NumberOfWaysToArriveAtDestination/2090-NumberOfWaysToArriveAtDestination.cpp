// Last updated: 10/5/2025, 8:53:35 AM
class Solution {
public:
    const int MOD = 1e9+7 ;
    typedef pair<long long,int>P;
    int countPaths(int n, vector<vector<int>>& roads) {
        //graph bnao 
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &road : roads)
        {
            int u = road[0] ; 
            int v = road[1] ;
            int time = road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue< P , vector<P> , greater<P>>pq;
        vector<long long>res(n,LLONG_MAX);
        vector<int>pathcount(n,0); 
        res[0] = 0 ;
        pathcount[0] = 1 ;
        pq.push({0 , 0});
        while(!pq.empty())
        {
            int node = pq.top().second;
            long long t = pq.top().first ;
            pq.pop();
            for(auto &ngbr : adj[node])
            {
                int neighbour = ngbr.first ;
                int timetaken = ngbr.second ;
                if(timetaken+t<res[neighbour])
                {
                    res[neighbour] = timetaken + t ;
                    pq.push({res[neighbour] , neighbour});
                    pathcount[neighbour] = pathcount[node];
                }
                else if (timetaken +t == res[neighbour])
                {
                    pathcount[neighbour]= (pathcount[neighbour] + pathcount[node] ) % MOD;
                }
            }
        }
        return pathcount[n-1];
        
    }
};