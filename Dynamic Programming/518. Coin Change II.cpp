Question Link: https://leetcode.com/problems/coin-change-ii/


// Approach 1:
class Solution {
public:
    
    vector<vector<int>> memo;
    int count(vector<int> &a, int idx, int k){
        int n=a.size();
        
        if(k==0) return 1;
        if(idx==n) return 0;
        
        if(memo[idx][k]!=-1) return memo[idx][k];
        
        int c=count(a,idx+1,k);
        
        if(k>=a[idx]) c += count(a,idx,k-a[idx]);
        
        return memo[idx][k]=c;
    }
    
    int change(int k, vector<int> &a) {
        int n=a.size();
        
        memo.resize(n,vector<int> (k+1,-1));
        return count(a,0,k);
    }
};


// Approach 2:
class Solution {
public:
    
    int change(int k, vector<int> &a) {
        int n=a.size();
        
		int dp[n+1][k+1];
        for(int i=0, j=1;j<=k;j++) dp[i][j]=0;
        for(int j=0, i=0;i<=n;i++) dp[i][j]=1;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1]) dp[i][j] += dp[i][j-a[i-1]];
            }
        }
        return dp[n][k];
    }
};


// Approach 3:
class Solution {
public:
	
    int change(int k, vector<int> &a) {
        int n=a.size();
        
        vector<int> dp(k+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=a[i];j<=k;j++){
                dp[j] += dp[j-a[i]];
            }
        }
        return dp[k];
    }
};
