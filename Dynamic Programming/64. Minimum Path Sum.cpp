Question Link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        dp[0][0]=grid[0][0];
        for(int i=0, j=1;j<m;j++) dp[i][j] += dp[i][j-1]+grid[i][j];
        for(int j=0, i=1;i<n;i++) dp[i][j] += dp[i-1][j]+grid[i][j];
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};
