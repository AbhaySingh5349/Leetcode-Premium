Question Link: https://leetcode.com/problems/the-maze/


// Approach :                                            
class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    bool possible(vector<vector<int>>& grid, int i, int j, vector<int>& destination){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]!=0) return false;
        
        if(i==destination[0] && j==destination[1]) return true;
        
        grid[i][j]=-1; // marking visited
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            while(x>=0 && y>=0 && x<n && y<m && grid[x][y]!=1){
                x += dxy[k][0];
                y += dxy[k][1];
            }
            
            x -= dxy[k][0], y -= dxy[k][1];
            if(possible(grid,x,y,destination)) return true;
        }
        return false;
    }
    
    bool hasPath(vector<vector<int>>& grid, vector<int>& start, vector<int>& destination) {
        return possible(grid,start[0],start[1],destination);
    }
};
