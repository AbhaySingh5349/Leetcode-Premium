Question Link: https://leetcode.com/problems/n-queens/

Time complexity: O(N!)
Unlike the brute force approach, we will only place queens on squares that aren't under attack. For the first queen, we have N options.
For the next queen, we won't attempt to place it in the same row as the first queen, and there must be at least one square attacked diagonally by the first queen as well. Thus, the maximum number of squares we can consider for the second queen is N - 2.
For the third queen, we won't attempt to place it in 2 rows already occupied by the first 2 queens, and there must be at least two squares attacked diagonally from the first 2 queens. Thus, the maximum number of squares we can consider for the third queen is N - 4.
While it costs O(N^2) to build each valid solution, the amount of valid solutions S(N) does not grow nearly as fast as N!N!, so O(N! + S(N) * N^2)

class Solution {
public:
    
    vector<vector<string>> ans;
    
    vector<bool> revDiagonal, diagonal, column;
    
    void resize(int n){
        revDiagonal.resize(2*n-1, false);
        diagonal.resize(2*n-1, false);
        column.resize(n, false);
    }
    
    bool isPossible(int n, int r, int c){
        if(diagonal[r+c]) return false;
        if(revDiagonal[r-c+n-1]) return false;
        if(column[c]) return false;
        return true;
    }
    
    void dfs(vector<string> &board, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isPossible(n,row,col)){
                diagonal[row+col]=true;
                revDiagonal[row-col+n-1]=true;
                column[col]=true;
                
                board[row][col]='Q';
                dfs(board,row+1,n);
                board[row][col]='.';
                
                column[col]=false;
                revDiagonal[row-col+n-1]=false;
                diagonal[row+col]=false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        resize(n);
        dfs(board,0,n);
        
        return ans;
    }
};
