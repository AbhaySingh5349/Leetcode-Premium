Question Link: https://leetcode.com/problems/partition-equal-subset-sum/


// Approach 1:
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        
        int sum = accumulate(a.begin(),a.end(),0);
        if(sum%2) return false;
        
        sum/=2;
        
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
        
        for(int i=0;i<n+1;i++) dp[i][0] = true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                dp[i][j] = dp[i-1][j];
                if(dp[i][j]==false && j>=a[i-1]) dp[i][j]=dp[i-1][j-a[i-1]];
            }
        }
        
        for(int j=1;j<sum+1;j++){
            if(dp[n][j] && dp[n][sum-j] && (j==sum-j)) return true;
        }
        return false;
    }
};


// Approach 2:
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        
        int sum = accumulate(a.begin(),a.end(),0);
        if(sum%2) return false;
        
        sum/=2;
        vector<vector<bool>> dp(2,vector<bool> (sum+1,false));
        
        dp[0][0] = true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                dp[i%2][j] = dp[!(i%2)][j];
                if(dp[i%2][j]==false && j>=a[i-1]) dp[i%2][j]=dp[!(i%2)][j-a[i-1]];
            }
        }
        
        return dp[n%2][sum];
    }
};


// Approach 3:
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        
        int sum = accumulate(a.begin(),a.end(),0);
        if(sum%2) return false;
        
        sum/=2;
        
        vector<bool> dp(sum+1,false);
        
        dp[0] = true;
        
        for(int i=0;i<n;i++){
            for(int j=sum;j>=a[i];j--){
                dp[j] = dp[j] || dp[j - a[i]];
            }
        }
        
        return dp[sum];
    }
};
