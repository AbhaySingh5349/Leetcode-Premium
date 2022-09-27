Question Link: https://leetcode.com/problems/minimum-window-subsequence/

class Solution {
public:
    string minWindow(string s, string p) {
        int n=s.length(), m=p.length();
        
        // dp[i][j]: min. len substring [k,i] from [0,i] having [0,j] as subsequence
        vector<vector<int>> dp(n+1,vector<int>(m+1,n+1));
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=1+dp[i-1][j];
                }
            }
        }
        
        int minlen=n+1, idx=-1;
        for(int i=1,j=m;i<n+1;i++){
            if(dp[i][j]<minlen){
                minlen=dp[i][j];
                idx=i-1;
            }
        }
        
        return (idx==-1 ? "":s.substr(idx-(minlen-1), minlen));
    }
};
