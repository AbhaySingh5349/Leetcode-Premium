Question Link: https://leetcode.com/problems/longest-common-subsequence/

// Approach 1:
class Solution {
public:
    
    vector<vector<int>> memo;
    
    int solve(string s1, string s2, int i, int j){
        int n=s1.length(), m=s2.length();
        
        if(i==n || j==m) return 0;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+solve(s1,s2,i+1,j+1);
        }else{
            ans=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
        }
        
        return memo[i][j]=ans;
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        memo.resize(n,vector<int>(m,-1));
        
        return solve(s1,s2,0,0);
    }
};

// Approach 2:
class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        
        int dp[n+1][m+1];
        for(int i=0,j=0;i<n+1;i++) dp[i][j]=0;
        for(int i=0,j=0;j<m+1;j++) dp[i][j]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
