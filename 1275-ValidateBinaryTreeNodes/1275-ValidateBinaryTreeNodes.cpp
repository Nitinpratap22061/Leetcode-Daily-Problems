// Last updated: 10/5/2025, 8:56:04 AM
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int>mp;
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++)
        {
            int lc=leftChild[i];
            int rc=rightChild[i];
            if(lc!=-1)
            {  //adjency map add left child;
                 adj[i].push_back(lc);

                if(mp.find(lc)!=mp.end()){
                    return false;
                }
                mp[lc]=i;
            }
             if(rc!=-1)
            {  //adjency map add left child;
                 adj[i].push_back(rc);

                if(mp.find(rc)!=mp.end()){
                    return false;
                }
                mp[rc]=i;
            }
        }

        //root find
        int root=-1;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end())//map m no parent so can be root
            {
                if(root!=-1){
                    return false;
                }
                root=i;
            }
        }
        if(root==-1)
        {
            return false;
        }

        //traversal bfs maarke check all node or not standard process h
        int count=0;
        queue<int>q; //imp int type ka hai
        vector<bool>visited(n,false);
        q.push(root);
        count=1;
        visited[root]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int &v:adj[node] )
            {
                if(visited[v]==true){
                    return false;
                }
                if(!visited[v])
                {
                    visited[v]=true;
                    count++;
                    q.push(v);
                }
            }
        }

        return count==n;

        
    }
};