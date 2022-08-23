Question Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<bool>> &visited){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0 || i==n || j==m) return;
        if(grid[i][j] < prev || visited[i][j]==true) return;
        
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            dfs(grid,x,y,grid[i][j],visited);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<bool>> pacific(n,vector<bool>(m,false)), atlantic(n,vector<bool>(m,false));
        
        // moving from boundaries to inwards cells where we can reach
        for(int j=0;j<m;j++){
            dfs(grid,0,j,INT_MIN,pacific);
            dfs(grid,n-1,j,INT_MIN,atlantic);
        }
        
        for(int i=0;i<n;i++){
            dfs(grid,i,0,INT_MIN,pacific);
            dfs(grid,i,m-1,INT_MIN,atlantic);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
