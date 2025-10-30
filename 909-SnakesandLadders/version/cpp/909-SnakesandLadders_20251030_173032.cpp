// Last updated: 10/30/2025, 5:30:32 PM
class Solution {
public:
int n ; 

  pair<int,int> solve(int val)
{
    int rowfromtop = (val - 1) / n;
    int reqrow = (n - 1) - rowfromtop;

    int reqcol = (val - 1) % n;

    if ((n % 2 == 1 && reqrow % 2 == 1) || (n % 2 == 0 && reqrow % 2 == 0))
        reqcol = n - 1 - reqcol;

    return {reqrow, reqcol};
}

    int snakesAndLadders(vector<vector<int>>& board) {

         n= board.size();
        

        int steps = 0 ; 
        queue<int>q ; 
       vector<vector<bool>>visited(n,vector<bool>(n,false)) ; 
        visited[n-1][0] = true ; 
        q.push(1) ; 

        while(!q.empty())
        {
            int size = q.size() ; 
            while(size--)
            {
                int x = q.front() ; 
                q.pop() ; 
                if(x==n*n)
                {
                    return steps ; 
                }

                for(int k=1 ; k<=6 ; k++)
                {
                    int val = x+k ; 

                    if(val>n*n)
                    {
                        break ; 
                    }
                    pair<int,int>cord = solve(val) ; 
                    int row = cord.first ; 
                    int col = cord.second ; 

                    if(visited[row][col])
                    {
                        continue;
                    }
                    visited[row][col] = true ; 

                    if(board[row][col]!=-1)
                    {

                        q.push(board[row][col]) ; 
                    }
                    else
                    {
                        q.push(val) ; 
                    }
                }
            }
            steps++ ; 
        }


         return -1 ; 


        
    }
};