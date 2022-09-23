Question Link: https://leetcode.com/problems/uncrossed-lines/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int>& a, vector<int>& b, int idx, int prevMatchIdx, vector<vector<int>> &memo){
        int n=a.size(), m=b.size();
        
        if(idx==n) return 0;
        
        if(memo[idx][prevMatchIdx+1] != 0) return memo[idx][prevMatchIdx+1];
        
        // not drwaing line for current idx
        int count=solve(a,b,idx+1,prevMatchIdx,memo);
        
        // drwaing line for current idx
        for(int i=prevMatchIdx+1;i<m;i++){
            if(a[idx] == b[i]){
                count = max(count,1+solve(a,b,idx+1,i,memo));
                break;
            }
        }
        
        return memo[idx][prevMatchIdx+1]=count;
    }
    
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n=a.size(), m=b.size();
        vector<vector<int>> memo(n,vector<int> (m+1,0));
        
        return solve(a,b,0,-1,memo);
    }
};

// Approach 2:
class Solution {
public:
    
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n=a.size(), m=b.size();
        
        // max. lines count taking 1st i elements from 'a' & j elements from 'b'
        vector<vector<int>> dp(n+1,vector<int> (m+1,0)); 
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
