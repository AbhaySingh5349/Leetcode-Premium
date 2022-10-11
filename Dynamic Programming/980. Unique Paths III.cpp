Question Link: https://leetcode.com/problems/unique-paths-iii/


// Approach :
class Solution {
public:
    
    int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int dfs(vector<vector<int>> &grid, int i, int j, int c){
        int n=grid.size(), m=grid[0].size();
        
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==-1) return 0;
        
        if(grid[i][j]==2){
            return (c==-1 ? 1:0);
        }
        
        int ans=0;
        grid[i][j]=-1;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            ans+=dfs(grid,x,y,c-1);
        }
        grid[i][j]=0;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int c=0;
        int si, sj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    c++;
                }else if(grid[i][j]==1){
                    si=i, sj=j;
                }
            }
        }
        return dfs(grid,si,sj,c);
    }
};
