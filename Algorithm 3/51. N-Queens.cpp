Question Link: https://leetcode.com/problems/n-queens/

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
