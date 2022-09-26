Question Link: https://leetcode.com/problems/longest-repeating-substring/


// Approach 1:
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n=s.length();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==s[j-1] && i!=j){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    #define lg long long
    lg int power(lg int a, lg int b, lg int mod){
        lg int ans=1;
        while(b>0){
            if(b%2==0){
                a=(a*a)%mod;
                b/=2;
            }else{
                ans=(ans*a)%mod;
                b--;
            }
        }
        return ans;
    }

    bool RollingHashAlgorithm(string s, int len) {
        int base=26;
        int mod1=1e9+5, mod2=1e9+7;

        lg int strHash1=0, strHash2=0;
        set<pair<lg int, lg int>> st;
        for(int i=0;i<len;i++){
            strHash1=(strHash1*base+(s[i]-'a'))%mod1;
            strHash2=(strHash2*base+(s[i]-'a'))%mod2;
        }
        st.insert({strHash1,strHash2});
        
        lg int pow1=power(base,len,mod1), pow2=power(base,len,mod2);
        for(int i=len;i<s.length();i++){
            strHash1=((strHash1*base+(s[i]-'a'))%mod1 - ((s[i-len]-'a')*pow1)%mod1 + mod1)%mod1;
            strHash2=((strHash2*base+(s[i]-'a'))%mod2 - ((s[i-len]-'a')*pow2)%mod2 + mod2)%mod2;
            
            if(st.find({strHash1,strHash2})!=st.end()) return true;
            st.insert({strHash1,strHash2});
        }
        return false;
    }
    
    
    int longestRepeatingSubstring(string s) {
        int n=s.length();
        
        int l=0, r=n-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(RollingHashAlgorithm(s,m)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};
