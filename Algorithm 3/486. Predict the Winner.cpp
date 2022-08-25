Question Link: https://leetcode.com/problems/predict-the-winner/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int>& a, int s, int e, vector<vector<int>> &memo){
        int n=a.size();
        if(s>e) return 0;
        
        if(memo[s][e]!=-1) return memo[s][e];
        
        if(s==e) return a[s];
        
        return memo[s][e] = max(a[s]-solve(a,s+1,e,memo), a[e]-solve(a,s,e-1,memo));
    }
    
    bool PredictTheWinner(vector<int>& a) {
        int n=a.size();
        if(n==1) return true;
        
        vector<int> pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return solve(a,0,n-1,memo)>=0;
    }
};

// Approach 2:
class Solution {
public:
    
    int solve(vector<int>& a, int s, int e){
        int n=a.size();
        if(s>e) return 0;
        if(s==e) return a[s];
        
        return max(a[s]-solve(a,s+1,e), a[e]-solve(a,s,e-1));
    }
    
    bool PredictTheWinner(vector<int>& a) {
        int n=a.size();
        if(n==1) return true;
        
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=a[i];
        
        for(int len=2;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
        return (dp[0][n-1]>=0);
    }
};
