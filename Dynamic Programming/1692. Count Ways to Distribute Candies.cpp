Question Link: https://leetcode.com/problems/count-ways-to-distribute-candies/


// Approach :
class Solution {
public:
    
    #define ll long long
    int waysToDistribute(int n, int k) {
        int mod = 1e9+7;
        
        vector<vector<ll int>> dp(n+1,vector<ll int>(k+1,0));
        for(int i=0;i<k+1;i++) dp[i][i]=1;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<k+1;j++){
                dp[i][j]=(j*dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        return dp[n][k];
    }
};
