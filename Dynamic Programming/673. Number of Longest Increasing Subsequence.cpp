Question Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        
        int dp[n], count[n];
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            count[i]=1;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    if(dp[i]<1+dp[j]){
                        count[i]=count[j];
                    }else if(dp[i]==1+dp[j]){
                        count[i]+=count[j];
                    }
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans) c += count[i];
        }
        
        return c;
    }
};
