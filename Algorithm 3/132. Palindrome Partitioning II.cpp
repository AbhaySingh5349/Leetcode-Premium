Question Link: https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    
    vector<vector<bool>> dp;
    
    int solve(string s, int idx){
        int n=s.length();
        if(idx==n) return -1; // because we added '+1' in previous call even when there was nothing to divide in end
        
        int ans=n-1;
        for(int i=idx;i<n;i++){
            if(dp[idx][i]==true){
                ans = min(ans,1+solve(s,i+1));
            }
        }
        return ans;
    }
    
    int minCut(string s) {
        int n=s.length();
        
        dp.resize(n,vector<bool> (n,false));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                
                if(s[i]==s[j]) dp[i][j] = (j-i<2 || dp[i+1][j-1]);
            }
        }
        
        return solve(s,0);
    }
};
