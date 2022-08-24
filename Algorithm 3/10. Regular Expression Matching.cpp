Question Link: https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(), m=p.length();
        
        bool dp[n+1][m+1];
        dp[0][0]=true;
        
        for(int i=1;i<n+1;i++) dp[i][0]=false;
        for(int j=1;j<m+1;j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-2]; // making (prev *) as null
            }else{
                dp[0][j]=false;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2]; // making (prev *) as null
                    if(dp[i][j]==false){
                        if(p[j-2]=='.' || p[j-2]==s[i-1]){
                            dp[i][j]=dp[i-1][j]; // consuming current (i-1)th character
                        }
                    }
                }else if(p[j-1]=='.' || p[j-1]==s[i-1]){
                    dp[i][j]=dp[i-1][j-1]; // checking strings till previous characters
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};
