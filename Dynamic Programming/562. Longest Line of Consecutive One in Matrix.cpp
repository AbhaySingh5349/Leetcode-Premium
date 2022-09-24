Question Link: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/


class Solution {
public:
    int longestLine(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int ans=0;
        
        int dp[n][m][4];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                
                for(int k=0;k<4;k++) dp[i][j][k]=1;
                
                // top
                if(i>0) dp[i][j][0] += dp[i-1][j][0];
                
                // left
                if(j>0) dp[i][j][1] += dp[i][j-1][1];
                
                // diagonal
                if (j>0 &&i>0) dp[i][j][2] += dp[i-1][j-1][2];
                
                // anti-diagonal
                if(j<m-1 && i>0) dp[i][j][3] += dp[i-1][j+1][3];
                
                ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
                ans=max(ans,max(dp[i][j][2],dp[i][j][3]));
            }
        }
        
        return ans;
    }
};
