Question Link: https://leetcode.com/problems/distinct-subsequences-ii/


// Approach :
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        
        int dp[n+1];
        dp[0]=1;
        
        int mod=1e9+7;
        
        map<char,int> mp; // to store previous occurence of a character
        for(int i=1;i<n+1;i++){
            char ch=s[i-1];
            dp[i]=dp[i-1]*2;
            if(mp.find(ch)!=mp.end()){
                int idx=mp[ch];
                dp[i]=(dp[i]%mod - dp[idx-1]%mod + mod)%mod;
            }
            mp[ch]=i;
            dp[i]%=mod;
        }
        return dp[n]-1;
    }
};
