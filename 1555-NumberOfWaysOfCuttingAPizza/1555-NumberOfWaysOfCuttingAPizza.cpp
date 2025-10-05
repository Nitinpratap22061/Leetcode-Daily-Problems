// Last updated: 10/5/2025, 8:55:16 AM
class Solution {
public:
    int m , n ;
    int apples[51][51];
    int t[51][51][12];
    const int M = 1e9+7;
    int solve(int i , int j , int k)
    {
        if(apples[i][j]<k)
        {
            return 0 ;
        }
        if(k==1)
        {
            if(apples[i][j]>=1)
            {
                return 1 ;
            }
            return 0 ; 
        }
        if(t[i][j][k]!=-1)
        {
            return t[i][j][k];
        }
        int ans = 0 ; 
        //horizontal cut try
        for(int h = i+1 ; h<m ; h++)
        {
            int lowerslice = apples[h][j];
            int upperslice = apples[i][j] - lowerslice;

            if(upperslice>=1 && lowerslice>=k-1)
            {
                ans=(ans+solve(h,j,k-1))%M;
            }
        }

        //vertical cut try 
        for(int v = j+1 ; v<n ; v++)
        {
            int right = apples[i][v];
            int left = apples[i][j]-right ; 
            if(left>=1 && right>=k-1)
            {
                ans=(ans+solve(i,v,k-1))%M;
            }
        }
        return t[i][j][k] = ans%M;

    }
    int ways(vector<string>& pizza, int k) {
        m = pizza.size() ; 
        n = pizza[0].size() ;
        memset(apples,0,sizeof(apples));
        memset(t,-1,sizeof(t));


        //fill the apple array 
        for(int i = m-1 ; i>=0 ; i--)
        {
            for(int j=n-1 ; j>=0 ; j--)
            {
                apples[i][j] = apples[i][j+1];
                for(int l = i ; l<m ; l++)
                {
                    if(pizza[l][j]=='A')
                    {
                        apples[i][j]+=1;
                    }
                }
            }
        }

        return solve(0 , 0 , k) ;  

        
    }
};