Question Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/


// Approach 1:
class Solution {
public:
    
    int findLength(vector<int> &a, vector<int> &b) {
        int n=a.size(), m=b.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        
        int maxlen=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++) maxlen=max(maxlen,dp[i][j]);
        }
        return maxlen; 
    }
};


// Approach 2:
class Solution {
public:
    
    #define ll long long
    
    ll int power(ll int a, ll int b, ll int mod){
        if(b==0) return 1;
        if(b%2==0) return power((a*a)%mod,b/2,mod);
        return (a*power(a,b-1,mod))%mod;
    }
    
    bool possible(vector<int> &a, vector<int> &b, int len, int base){
        int n=a.size(), m=b.size();
        
        int mod1=1e9+5, mod2=1e9+7;
        
        ll int pow1=power(base,len,mod1);
        ll int pow2=power(base,len,mod2);
        
        set<pair<ll int,ll int>> st;
        ll int hash1=0, hash2=0;
        for(int i=0;i<len;i++){
            hash1=(hash1*base+a[i])%mod1;
            hash2=(hash2*base+a[i])%mod2;
        }
        st.insert({hash1,hash2});
        for(int i=len;i<n;i++){
            hash1=((hash1*base+a[i])%mod1-((a[i-len])*pow1)%mod1 +mod1)%mod1;
            hash2=((hash2*base+a[i])%mod2-((a[i-len])*pow2)%mod2 +mod2)%mod2;
            
            st.insert({hash1,hash2});
        }
        
        ll int hash3=0, hash4=0;
        for(int i=0;i<len;i++){
            hash3=(hash3*base+b[i])%mod1;
            hash4=(hash4*base+b[i])%mod2;
        }
        if(st.find({hash3,hash4})!=st.end()) return true;
        for(int i=len;i<m;i++){
            hash3=((hash3*base+b[i])%mod1-((b[i-len])*pow1)%mod1 +mod1)%mod1;
            hash4=((hash4*base+b[i])%mod2-((b[i-len])*pow2)%mod2 +mod2)%mod2;
            
            if(st.find({hash3,hash4})!=st.end()) return true;
        }
        
        return false;
    }
    
    int findLength(vector<int> &a, vector<int> &b) {
        int n=a.size(), m=b.size();
        
        int base = max(*max_element(a.begin(),a.end()),*max_element(b.begin(),b.end())) + 1;
        int l=0, r=min(n,m);
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(possible(a,b,mid,base)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};
