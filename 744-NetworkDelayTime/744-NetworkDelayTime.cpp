// Last updated: 10/5/2025, 8:57:55 AM
class Solution {
public:
   typedef pair<int,int>P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         unordered_map<int, vector<pair<int, int>>> mp;
         for(auto &ele : times)
         {
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];

            mp[u].push_back({v,w});
         }
         vector<int>res(n+1,INT_MAX);
         priority_queue< P , vector<P> , greater<P>>pq;
         res[k] =0;
         pq.push({0,k});
         while(!pq.empty())
         {
            auto curr = pq.top() ;
            pq.pop();
            int d = curr.first ;
            int node  = curr.second ; 
            for(auto &vec : mp[node])
            {
                int next = vec.first;
                int wt =  vec.second ; 
                if(wt+d < res[next])
                {
                    res[next] = wt+d ;
                    pq.push({wt+d , next});
                }
            }
         }

         int ans  = 0 ;
          for (int i = 1; i <= n; i++) { 
            if (res[i] == INT_MAX) return -1; 
            ans = max(ans, res[i]);
        }
  return ans;


        
    }
};