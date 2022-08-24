Question Link: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    map<int,map<char,bool>> row, col, sub;
    bool solve(vector<vector<char>>& grid, int pos){
        int n=9;
        if(pos==n*n) return true; 
        
        int i=pos/n, j=pos%n;
        int g=(i/3)*3+j/3;
        
        if(grid[i][j]!='.'){
            if(solve(grid,pos+1)) return true;
        }else{
            for(int d=1;d<=9;d++){
                if(row[i][d]==false && col[j][d]==false && sub[g][d]==false){
                    row[i][d]=true;
                    col[j][d]=true;
                    sub[g][d]=true;
                    grid[i][j]=d+'0';
                    if(solve(grid,pos+1)) return true;
                    row[i][d]=false;
                    col[j][d]=false;
                    sub[g][d]=false;
                    grid[i][j]='.';
                }
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& grid) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int d=grid[i][j]-'0';
                
                int g=(i/3)*3+j/3;
                row[i][d]=true;
                col[j][d]=true;
                sub[g][d]=true;
            }
        }
        solve(grid,0);
    }
};
