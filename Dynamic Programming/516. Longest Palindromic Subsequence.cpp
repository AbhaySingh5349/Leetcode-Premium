Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/

// Approach 1:
class Solution {
public:
    
    int solve(string s, int i, int j, vector<vector<int>> &memo){
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(memo[i][j]!=0) return memo[i][j];
        
        int ans=0;
        if(s[i]==s[j]){
            ans=2+solve(s,i+1,j-1,memo);
        }else{
            ans=max(solve(s,i+1,j,memo),solve(s,i,j-1,memo));
        }
        
        return memo[i][j]=ans;
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> memo(n,vector<int>(n,0));
        
        return solve(s,0,n-1,memo);
    }
};


// Approach 2:
class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        
        for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};


// Approach 3:
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        
        int dp[n+1][n+1];
        for(int i=0;i<n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};
