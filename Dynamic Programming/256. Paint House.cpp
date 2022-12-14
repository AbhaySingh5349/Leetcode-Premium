Question Link: https://leetcode.com/problems/paint-house/

class Solution {
public:
    int minCost(vector<vector<int>> &a) {
        int n=a.size();
        
        int dp[n][3];
        dp[0][0]=a[0][0], dp[0][1]=a[0][1], dp[0][2]=a[0][2];
        
        for(int i=1;i<n;i++){
            dp[i][0]=a[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=a[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=a[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        
        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};
