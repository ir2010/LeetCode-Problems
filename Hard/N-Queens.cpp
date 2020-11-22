class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {    
        vector<vector<string>> output;
        vector<string> board;
        for(int i=0; i<n; i++)
        {
            string s = "";
            for(int j=0; j<n; j++)
                s+='.';
            board.push_back(s);
        }
        nqueens(output, n, 0, board);
        return output;
    }
    
    void nqueens(vector<vector<string>>& output, int n, int col, vector<string> board)
    {
        if(col >= n)
        {
            output.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++)
        {
            if(isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                nqueens(output, n, col+1, board);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string> board, int r, int c, int n)
    {
        for(int i=0; i<c; i++)
            if(board[r][i] == 'Q')
                return false;
        
        for(int i=r, j=c; i<n && j<n; i++, j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        for(int i=r, j=c; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        for(int i=r, j=c; i<n && j>=0; i++, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        for(int i=r, j=c; i>=0 && j<n ;i--, j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};