Question Link: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        
        int c=0;
        
        int dp[n][n];
        memset(dp,false,sizeof(dp));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                
                if(s[i]==s[j]) dp[i][j]=(j-i<2 || dp[i+1][j-1]);
                
                c+=dp[i][j];
            }
        }
        return c;
    }
};
