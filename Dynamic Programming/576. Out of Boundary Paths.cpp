Question Link: https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    const unsigned int mod=1000000007;
    int memo[51][51][51];
    int dxy[4][4]={{-1,0},{0,1},{1,0},{0,-1}};
    
    int solve(int n, int m, int move, int i, int j){
        if(i<0 || j<0 || i==n || j==m) return 1;
        if(move==0) return 0;
        
        if(memo[i][j][move]!=-1) return memo[i][j][move];
        
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            ans+=solve(n,m,move-1,x,y);
            ans%=mod;
        }
        return memo[i][j][move]=ans;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
        return solve(n,m,maxMove,startRow,startColumn);
    }
};
