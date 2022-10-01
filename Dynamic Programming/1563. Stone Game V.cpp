Question Link: https://leetcode.com/problems/stone-game-v/


// Approach 1:
class Solution {
public:
    vector<int> pre;
    vector<vector<int>> memo;
    
    int solve(vector<int>& stone, int s, int e){
        if(s==e) return 0;
        
        if(memo[s][e]!=-1) return memo[s][e];
        
        int ans=0;
        for(int i=s;i<e;i++){
            int left=pre[i]-(s>0 ? pre[s-1]:0);
            int right=pre[e]-pre[i];
            
            if(left<right){
                ans=max(ans,left+solve(stone,s,i));
            }else if(left>right){
                ans=max(ans,right+solve(stone,i+1,e));
            }else{
                ans=max(ans,max(left+solve(stone,s,i),right+solve(stone,i+1,e)));
            }
        }
        
        return memo[s][e]=ans;
    }
    
    int stoneGameV(vector<int>& a) {
        int n=a.size();
        
        pre.resize(n);
        memo.resize(n,vector<int>(n,-1));
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        
        return solve(a,0,n-1);
    }
};


// Approach 2:
class Solution {
public:
    
    int stoneGameV(vector<int>& stone) {
        int n=stone.size();
        
        int dp[n][n];
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n-len+1; i++) {
                int j = i+len-1, res = 0;
                for(int k = i; k < j; k++) {
                    int left = pre[k] - (i>0 ? pre[i-1]:0), right = pre[j] - pre[k];
                    if(left < right) {
                        res = max(res, left + dp[i][k]);
                    } else if(left > right) {
                        res = max(res, right + dp[k+1][j]);
                    } else {
                        res = max(res, left + dp[i][k]);
                        res = max(res, right + dp[k+1][j]);
                    }
                }  
                
                dp[i][j] = res;
            }
        }
        return dp[0][n-1]; 
    }
};
