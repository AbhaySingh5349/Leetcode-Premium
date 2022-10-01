Question Link: https://leetcode.com/problems/stone-game-iv/


// Approach 1:
class Solution {
public:
    
    int memo[100001];
    
    bool possible(int n){
        if(n==0) return false;
        
        if(memo[n]!=-1) return memo[n];
        
        for(int i=1;i*i<=n;i++){
            if(!possible(n-i*i)){
                return memo[n]=true;
            }
        }
        return memo[n]=false;
    }
    
    bool winnerSquareGame(int n){
        memset(memo,-1,100001);
        
        return possible(n);
    }
};


// Approach 2:
class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        dp[0]=false;
        dp[1]=true;
        
        for(int i=2;i<=n;i++){
            dp[i]=false;
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
