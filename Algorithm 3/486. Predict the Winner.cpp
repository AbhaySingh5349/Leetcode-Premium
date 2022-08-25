Question Link: https://leetcode.com/problems/predict-the-winner/

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
