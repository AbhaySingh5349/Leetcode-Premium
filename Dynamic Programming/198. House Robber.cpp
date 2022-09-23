Question Link: https://leetcode.com/problems/house-robber/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int> &a, int idx, vector<int> &memo){
        if(idx >= a.size()) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        // include
        int p1 = a[idx] + solve(a,idx+2,memo);
        
        // exclude
        int p2 = solve(a,idx+1,memo);
        
        return memo[idx] = max(p1,p2);
    }
    
    int rob(vector<int> &a) {
        vector<int> memo(a.size(),-1);
        return solve(a,0,memo);
    }
};


// Approach 2:
class Solution {
public:
    
    int rob(vector<int> &a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int include[n], exclude[n];
        include[0]=a[0], exclude[0]=0;
        include[1]=a[1], exclude[1]=a[0];
        
        for(int i=2;i<n;i++){
            include[i]=a[i]+exclude[i-1];
            exclude[i]=max(include[i-1],exclude[i-1]);
        }
        return max(include[n-1],exclude[n-1]);
    }
};


// Approach 3:
class Solution {
public:
    
    int rob(vector<int> &a) {
        int n=a.size();
        if(n==1) return a[0];
        
        int dp[n];
        dp[0]=a[0], dp[1]=max(a[0],a[1]);
        for(int i=2;i<n;i++) dp[i]=max(dp[i-1],a[i]+dp[i-2]);
        
        return dp[n-1]; 
    }
};
