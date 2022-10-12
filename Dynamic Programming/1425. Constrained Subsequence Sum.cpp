Question Link: https://leetcode.com/problems/constrained-subsequence-sum/


// Approach 1:                                            
class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n=a.size();
        int dp[n];
        dp[0]=a[0];
        int ans=a[0];
        
        for(int i=1;i<n;i++){
            dp[i]=a[i];
            for(int j=i-1;j>=max(0,i-k);j--){
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n=a.size();
        
        int ans=a[0];
        
        priority_queue<pair<int,int>> pq;
        pq.push({a[0],0});
        for(int i=1;i<n;i++){
            int cur=a[i];
            while(pq.size()>0 && (i-pq.top().second)>k) pq.pop();
            
            if(pq.size()>0){
                cur=max(cur,pq.top().first+a[i]);
            }
            ans=max(ans,cur);
            pq.push({cur,i});
        }
        return ans;
    }
};
