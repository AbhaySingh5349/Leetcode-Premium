Question Link: https://leetcode.com/problems/dungeon-game/

// Approach 1:
class Solution {
public:
    
    bool isPossible(vector<vector<int>>& grid, int val) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m,INT_MIN));
        
        dp[0][0]=grid[0][0]+val;
        
        for(int i=0,j=1;j<m;j++){
            if(dp[i][j-1]>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+grid[i][j]);
        }
        for(int i=1,j=0;i<n;i++){
            if(dp[i-1][j]>0) dp[i][j]=dp[i-1][j]+grid[i][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i-1][j]>0) dp[i][j]=dp[i-1][j]+grid[i][j];
                if(dp[i][j-1]>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        return (dp[n-1][m-1]>0);
    }
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int l=1, r=1e6;
        while(l<r){
            int m=l+(r-l)/2;
            if(isPossible(grid,m)){
                r=m;
            }else{
                l=m+1;
            }
        } 
        return l;
    }
};

// Approach 2:
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
