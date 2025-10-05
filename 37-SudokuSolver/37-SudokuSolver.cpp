// Last updated: 10/5/2025, 9:02:30 AM
class Solution {
public:
          int check = 0 ;
          bool isValid(vector<vector<char>>& board, char ch, int row, int col) {
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == ch || board[i][col] == ch)
            return false;
    }

    int startRow = 3 * (row / 3), startCol = 3 * (col / 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[startRow + i][startCol + j] == ch)
                return false;
        }
    }

    return true;
}
 
    void solve(vector<vector<char>>& board , int i , int j )
    {
        if(i==9)
        {
            check = 1 ; 
            return ; 
        }
        
       else  if(board[i][j]!='.')
        {
            if(j !=8){
                solve(board,i,j+1);
            }
            else 
            {
                solve(board,i+1,0);
            }
            
        } 
        else
        {
            for(char ch='1' ; ch<='9' ; ch++)
            {
                if(isValid(board , ch , i , j))
                {
                    board[i][j]=ch;
                    if(j!=8)
                    {
                    solve(board , i , j+1);
                    }
                    else
                    {
                        solve(board,i+1,0);
                    }
                    if(check==1) return;
                    board[i][j]='.';
                    
                }
            }
        }

    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board , 0 , 0);
       check = 0 ;
    }
};
