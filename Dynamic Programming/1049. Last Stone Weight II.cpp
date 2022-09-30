Question Link: https://leetcode.com/problems/last-stone-weight-ii/


// Approach 1:
class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0,j=1;j<sum+1;j++) dp[i][j]=false;
        for(int i=0,j=0;i<n+1;i++) dp[i][j]=true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                dp[i][j]=dp[i-1][j];
                if(dp[i][j]==false && j>=a[i-1]) dp[i][j]=dp[i-1][j-a[i-1]];
            }
        }
        
        int ans=sum;
        for(int i=n,j=1;j<sum+1;j++){
            if(dp[i][j] && dp[i][sum-j]) ans=min(ans,abs(sum-2*j));
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=a[i];j--) dp[j] = dp[j] || dp[j-a[i]];
        }
        
        int ans=sum;
        for(int j=1;j<sum+1;j++){
            if(dp[j] && dp[sum-j]) ans=min(ans,abs(sum-2*j));
        }
        return ans;
    }
};
