Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    
    int solve(vector<int>& a, int idx, bool prev, int k, vector<vector<vector<int>>> &memo){
        int n=a.size();
        if(idx==n || k==0) return 0;
        
        if(memo[idx][k][prev]!=-1) return memo[idx][k][prev];
        
        int ans=0;
        if(prev==0){
            // buy stock
            ans=max(ans,-a[idx]+solve(a,idx+1,1,k,memo));
        }else{
            // sell stock
            ans=max(ans,a[idx]+solve(a,idx+1,0,k-1,memo));
        }
        
        // skip stock
        ans=max(ans,solve(a,idx+1,prev,k,memo));
        
        return memo[idx][k][prev]=ans;
    }
    
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k+1, vector<int>(2,-1)));
        
        return solve(a,0,0,k,memo); 
    }
};
