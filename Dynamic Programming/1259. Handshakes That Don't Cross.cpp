Question Link: https://leetcode.com/problems/handshakes-that-dont-cross/

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
