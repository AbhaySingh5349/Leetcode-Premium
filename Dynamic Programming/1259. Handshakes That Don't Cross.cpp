Question Link: https://leetcode.com/problems/handshakes-that-dont-cross/


// Approach 1:
class Solution {
public:
    
    #define ll long long
    
    map<int,int> mp;
    const unsigned int mod=1000000007;
    
    int numberOfWays(int n) {
        if(n==0) return 1;
        if(n%2) return 0;
        
        if(mp.find(n)!=mp.end()) return mp[n];
        
        ll int c=0;
        for(int k=0;k<n;k+=2){
            int left = k, right = n-2-k;
            
            c += ((ll)numberOfWays(left))*((ll)numberOfWays(right));
            c %= mod;
        }
        return mp[n]=(int)c; 
    }
};


// Approach 2: Catalan Numbers
class Solution {
public:
    
    #define ll long long
    
    const unsigned int mod=1000000007;
    
    int numberOfWays(int n) {        
        int c = n/2;
        int dp[c+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<c+1;i++){
            ll int c=0;
            for(int j=0;j<i;j++){
                c += ((ll)dp[j])*((ll)dp[i-1-j]);
                c %= mod;
            }
            dp[i]=c;
        }
        return dp[c];
    }
};
