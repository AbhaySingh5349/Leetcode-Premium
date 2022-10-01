Question Link: https://leetcode.com/problems/stone-game-ii/


// Approach :
class Solution {
public:
    
    vector<int> pre;
    vector<vector<vector<int>>> memo;
    int solve(vector<int>& a, int idx, int m, bool alice){
        int n=a.size();
        
        if(idx==n || m>n) return 0;
        
        if(memo[idx][m][alice]!=-1) return memo[idx][m][alice];
        
        int ans;
        
        if(alice){
            // alice will maximize his stones
            ans=0;
            for(int i=idx;i<min(n,idx+2*m);i++){
                int val=(pre[i]-(idx>0 ? pre[idx-1]:0));
                ans=max(ans,val+solve(a,i+1,max(m,i-idx+1),!alice));
            }
        }else{
            // bob will minimize stones for 'alice'
            ans=pre[n-1];
            for(int i=idx;i<min(n,idx+2*m);i++){
                ans=min(ans,solve(a,i+1,max(m,i-idx+1),!alice));
            }
        }
        
        return memo[idx][m][alice]=ans;
    }
    
    int stoneGameII(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        
        pre.resize(n);
        memo.resize(n,vector<vector<int>>(n,vector<int>(2,-1)));
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        
        return solve(a,0,1,true);
    }
};
