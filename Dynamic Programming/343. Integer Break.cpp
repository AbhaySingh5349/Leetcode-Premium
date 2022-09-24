Question Link: https://leetcode.com/problems/integer-break/


// Approach 1:
class Solution {
public:
    
    int solve(int n, vector<int> &memo){
        if(n==1) return 1;
        
        if(memo[n]!=-1) return memo[n];
        
        int ans=1*(n-1);
        for(int num=1;num<n;num++){
            int product = num*max(solve(n-num,memo),n-num);
            ans=max(ans,product);
        }
        return memo[n]=ans;
    }
    
    int integerBreak(int n) {
        vector<int> memo(n+1,-1);
        return solve(n,memo);
    }
};


// Approach 2:
class Solution {
public:
	
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        
        for(int i=4;i<n+1;i++){
            int res=1*(i-1);
            for(int j=1;j<i;j++){
                int product = j*max(dp[i-j],i-j);
                res = max(res,product);
            }
            dp[i]=res;
        }            
        return dp[n];
    }
};


// Approach 3:
class Solution {
public:
	
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        
        for(int i=5;i<n+1;i++){
            dp[i]=3* max(i-3, dp[i-3]);
        }          
        return dp[n];
    }
};
