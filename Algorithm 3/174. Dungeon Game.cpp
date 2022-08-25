Question Link: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int dp[n][m];
        dp[n-1][m-1]=min(0,grid[n-1][m-1]);
        for(int i=n-1,j=m-2;j>=0;j--) dp[i][j]=min(0,dp[i][j+1]+grid[i][j]);
        for(int i=n-2,j=m-1;i>=0;i--) dp[i][j]=min(0,dp[i+1][j]+grid[i][j]);
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=min(0,max(dp[i+1][j],dp[i][j+1])+grid[i][j]);
            }
        }
        return (dp[0][0]>1 ? 1:1-dp[0][0]);
    }
};
