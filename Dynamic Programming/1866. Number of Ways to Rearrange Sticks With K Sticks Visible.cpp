Question Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/


// Approach :
class Solution {
public:
    #define mod 1000000007
    
    int memo[1001][1001];
    long long int solve(int n, int k){
        if(n==k) return 1;
        if(k==0) return 0;
        
        if(memo[n][k]!=-1) return memo[n][k];
        
        long long int ans=0;
        long long int x=solve(n-1,k-1)%mod; // making visible (keeping largest available to rightmost place)
        long long int y=(n-1)*solve(n-1,k)%mod; // making invisible (keeping non-largest to rightmost place)
        
        ans+=(x+y)%mod;
        
        return memo[n][k]=ans;
    }
    
    int rearrangeSticks(int n, int k) {
        memset(memo,-1,sizeof(memo));
        
        return solve(n,k);
    }
};
