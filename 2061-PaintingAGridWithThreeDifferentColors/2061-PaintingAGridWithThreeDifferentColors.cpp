// Last updated: 10/5/2025, 8:53:37 AM
class Solution {
public:
    vector<string>colState ; 
    const int M = 1e9+7;
    vector<vector<int>>t ; 
    void fillColState(string currChar , char prev , int l , int m)
    {
        if(l==m)
        {
            colState.push_back(currChar) ; 
            return ; 
        }
        for(char ch:{'R' , 'G' , 'B'})
        {
            if(ch==prev) continue ; 
            fillColState(currChar+ch , ch ,l+1 , m);
        }
    }
    int solve(int col , int prevIdx , int m)
    {
        if(col == 0 )
        {
            return 1 ; 
        }
        int ways = 0 ;
        if(t[col][prevIdx]!=-1)
        {
            return t[col][prevIdx] ; 
        }
        string prevState = colState[prevIdx];
        for(int i = 0 ; i<colState.size() ; i++)
        {
            if(i==prevIdx) continue ; 
            string currState = colState[i] ; 
            bool valid = true ; 
            for(int j = 0  ; j<m ; j++)
            {
                if(prevState[j] == currState[j])
                {
                    valid = false;
                    break ; 

                }
            }
            if(valid)
            {
                ways = (ways + solve(col-1 , i , m))%M;
            }
        }
        return t[col][prevIdx] = ways ; 
    }
    int colorTheGrid(int m, int n) {
        //s-1 :- fill the first colstate me jo jo daal skte and uske aq fill next 
        fillColState("" , '#' , 0 , m);
        //s-2 :- in sb colstate ke liye had to call solve
        int res = 0 ;
        int collStateSize = colState.size();
        t = vector<vector<int>>(n,vector<int>(collStateSize , -1));
        for(int i = 0 ; i<colState.size() ; i++)
        {
            res = (res +  solve(n-1 , i , m)) % M ; 

        }
        return res % M ; 
        
        
    }
};