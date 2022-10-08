Question Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/


// Approach 1:
class Solution {
public:
    
    int memo[301][301];
    int dxy[3][2]={{1,0},{0,1},{1,1}};
    
    int count(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans=max(m,n);
        for(int k=0;k<3;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            
            ans=min(ans,count(grid,n,m,x,y));
        }
        return memo[i][j]=ans+1;
    }
    
    int countSquares(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=count(grid,n,m,i,j);
                }
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    int countSquares(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size();
        
        int dp[n][m];
    	int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1+min((i<n-1 && j<m-1 ? dp[i+1][j+1]:0),min((i<n-1 ? dp[i+1][j]:0),(j<m-1 ? dp[i][j+1]:0)));
                }
                ans+=dp[i][j];
            }
        } 
        return ans;
    }
};
