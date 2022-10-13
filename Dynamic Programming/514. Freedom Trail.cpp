Question Link: https://leetcode.com/problems/freedom-trail/


// Approach :                                            
class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(string ring, string key, int ptr, int idx){
        int n=ring.length(), m=key.length();
        
        if(idx == m) return 0;
        
        if(memo[ptr][idx] != -1) return memo[ptr][idx];
        
        int ans=INT_MAX/2;
        for(int i=0;i<n;i++){
            if(ring[i] == key[idx]){
                // we can reach ith position clockwise or anti-clockwise
                ans=min(ans, min(abs(i-ptr), n-abs(i-ptr)) + 1 + solve(ring,key,i,idx+1));
            }
        }
        return memo[ptr][idx]=ans;
    }
    
    int findRotateSteps(string ring, string key) {
        int n=ring.length(), m=key.length();
        
        memo.resize(n,vector<int>(m,-1));
        return solve(ring,key,0,0);
    }
};
