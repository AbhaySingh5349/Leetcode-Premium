Question Link: https://leetcode.com/problems/stone-game-vii/


// Approach 1:
class Solution {
public:
    
    int pre[1001];
    int memo[1001][1001];
    int solve(vector<int>& a, int s, int e){
        if(s==e) return 0;
        
        if(memo[s][e]!=-1) return memo[s][e];
        int ans=max((pre[e]-pre[s])-solve(a,s+1,e), (pre[e-1]-(s>0 ? pre[s-1]:0))-solve(a,s,e-1));
        
        return memo[s][e]=ans;
    }
    
    int stoneGameVII(vector<int>& a) {
        int n=a.size();
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        memset(memo,-1,sizeof(memo));
        
        return solve(a,0,n-1);
    }
};


// Approach 2:
class Solution {
public:
    
    int stoneGameVII(vector<int>& a) {
        int n=a.size();
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        
        int dp[n+1][n];
        memset(dp,0,sizeof(dp));
        
        for(int len=2;len<n+1;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                dp[i][j]=max((pre[j]-pre[i])-dp[i+1][j], (pre[j-1]-(i>0 ? pre[i-1]:0))-dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};
