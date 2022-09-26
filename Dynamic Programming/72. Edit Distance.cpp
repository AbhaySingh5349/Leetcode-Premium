Question Link: https://leetcode.com/problems/edit-distance/


// Approach 1:
class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(string s, int i, string p, int j){
        int n=s.length(), m=p.length();
        
        if(j==m) return n-i;
        if(i==n) return m-j;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans=INT_MAX/2;
        if(s[i]==p[j]){
            ans=solve(s,i+1,p,j+1);
        }else{
            // insert
            int c1=solve(s,i,p,j+1);
            
            // delete
            int c2=solve(s,i+1,p,j);
            
            // replace
            int c3=solve(s,i+1,p,j+1);
            
            ans=min(c1,min(c2,c3))+1;
        }
        return memo[i][j]=ans;
    }
    
    int minDistance(string s, string p) {
        int n=s.length(), m=p.length();
        memo.resize(n,vector<int>(m,-1));
        
        return solve(s,0,p,0);
    }
};


// Approach 2:
class Solution {
public:
    
    int minDistance(string s, string p) {
        int n=s.length(), m=p.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX/2));
        
        for(int i=0,j=0;j<m+1;j++) dp[i][j]=j;
        for(int i=0,j=0;i<n+1;i++) dp[i][j]=i;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == p[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int c1=dp[i][j-1]; // insert
                    int c2=dp[i-1][j]; // delete
                    int c3=dp[i-1][j-1]; // replace
                    
                    dp[i][j]=min(c1,min(c2,c3))+1;
                }
            }
        }
        return dp[n][m];
    }
};
