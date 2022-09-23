Question Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX/2));
        
        dp[0][0]=0;
        for(int i=0,j=1;j<m+1;j++) dp[i][j]=dp[i][j-1]+s2[j-1]-'a'+97;
        for(int j=0,i=1;i<n+1;i++) dp[i][j]=dp[i-1][j]+s1[i-1]-'a'+97;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(s1[i-1]-'a'+97 + dp[i-1][j], s2[j-1]-'a'+97 + dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
