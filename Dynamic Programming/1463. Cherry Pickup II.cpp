Question Link: https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    
    int memo[71][71][71];
    int solve(vector<vector<int>>& grid, int n, int m, int r, int c1, int c2){
        if(r==n || c1<0 || c2<0 || c1==m || c2==m) return 0;
        
        if(memo[r][c1][c2]!=-1) return memo[r][c1][c2];
        
        int total=0;
        if(c1==c2){
            total+=grid[r][c1];
        }else{
            total+=grid[r][c1]+grid[r][c2];
        }
        int ans=INT_MIN;
        for(int col1=-1;col1<=1;col1++){
            for(int col2=-1;col2<=1;col2++){
                int nc1=c1+col1;
                int nc2=c2+col2;
                ans=max(ans,solve(grid,n,m,r+1,nc1,nc2));
            }
        }
        
        return memo[r][c1][c2]=total+ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        int n=grid.size();
        int m=grid[0].size();
        
        return solve(grid,n,m,0,0,m-1);
    }
};
