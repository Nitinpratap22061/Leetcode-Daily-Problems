// Last updated: 10/5/2025, 8:55:58 AM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        vector<double>result(n,0);
        for(int i=0 ;i<edges.size() ; i++)
        {
            int u=edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>>pq;

        result[start_node] = 1 ; //strat to start prob 100percent
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            double p = curr.first ;
            int node = curr.second;

           for(auto &it : adj[node])
           {
                  double p1 = it.second;
                  int adjNode = it.first;
                  if(p1*p > result[adjNode])
                  {
                    result[adjNode] = p1*p;
                    pq.push({p1*p,adjNode});
                  }
           }
        }
        return result[end_node];
        
    }
};