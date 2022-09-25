Question Link: https://leetcode.com/problems/perfect-squares/

// Approach 1:
class Solution {
public:
    
    vector<int> memo;
    
    int solve(int n){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        return memo[n]=ans;
    }
    
    int numSquares(int n) {
        memo.resize(n+1,-1);
        return solve(n);
    }
};

// Approach 2:
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++) dp[i]=min(dp[i],1+dp[i-j*j]);
        }
        return dp[n]; 
    }
};
