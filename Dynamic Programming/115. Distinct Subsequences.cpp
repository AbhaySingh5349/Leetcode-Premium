Question Link: https://leetcode.com/problems/distinct-subsequences/


// Approach 1:
class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(string s, string p, int i, int j){
        int n=s.length(), m=p.length();
        if(j==m) return 1;
        if(i==n || j==m) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans=0;
        if(s[i]==p[j]) ans+=solve(s,p,i+1,j+1);
        ans+=solve(s,p,i+1,j);
        
        return memo[i][j]=ans;
    }
    
    int numDistinct(string s, string p) {
        int n=s.length(), m=p.length();
        
        memo.resize(n,vector<int>(m,-1));
        return solve(s,p,0,0);
    }
};


// Approach 2:
class Solution {
public:
    
    int numDistinct(string s, string p) {
        int n=s.length(), m=p.length();
        
        unsigned int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n+1;i++) dp[i][0]=1;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
