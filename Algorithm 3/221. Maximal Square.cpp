Question Link: https://leetcode.com/problems/maximal-square/

// Approach 1:
class Solution {
public:
    
    int dxy[3][2]={{0,1},{1,1},{1,0}};
    
    int getSide(vector<vector<char>>& grid, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return 0;
        }
        int ans=max(n,m);
        for(int k=0;k<3;k++){
            int x=i+dxy[k][0];
            int y=j+dxy[k][1];
            ans=min(ans,getSide(grid,n,m,x,y));
        } 
        return ans+1;
    }
    int maximalSquare(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans=max(ans,getSide(grid,n,m,i,j));
                }
            }
        }
        return ans*ans;
    }
};

// Approach 2:
class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int dp[n][m];
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]=='0'){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1+min((i<n-1 && j<m-1 ? dp[i+1][j+1]:0),min((i<n-1 ? dp[i+1][j]:0),(j<m-1 ? dp[i][j+1]:0)));
                }
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;
    }
};
