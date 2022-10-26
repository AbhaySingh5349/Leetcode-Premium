Question Link: https://leetcode.com/problems/repeated-dna-sequences/


// Approach :    
class Solution {
public:
    
    #define ll long long
    
    ll int power(ll int a, ll int b, ll int mod){
        if(b==0) return 1;
        
        if(b%2==0) return power((a*a)%mod, b/2, mod);
        return (a%mod*power(a,b-1,mod)%mod)%mod;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        
        set<string> st;
        
        set<pair<ll int,ll int>> visited;
        ll int hash1=0, hash2=0;
        
        int mod1=1e9+5, mod2=1e9+7;
        
        for(int i=0;i<10;i++){
            hash1=(hash1*26+(s[i]-'A'))%mod1;
            hash2=(hash2*26+(s[i]-'A'))%mod2;
        }
        visited.insert({hash1,hash2});
        
        ll int pow1=power(26,10,mod1);
        ll int pow2=power(26,10,mod2);
        for(int i=10;i<n;i++){
            hash1=((hash1*26+(s[i]-'A'))%mod1-((s[i-10]-'A')*pow1)%mod1 + mod1)%mod1;
            hash2=((hash2*26+(s[i]-'A'))%mod2-((s[i-10]-'A')*pow2)%mod2 + mod2)%mod2;
            
            if(visited.find({hash1,hash2})!=visited.end()){
                string sub=s.substr(i-10+1,10);
                st.insert(sub);
            }
            
            visited.insert({hash1,hash2});
        }
        
        vector<string> ans(st.begin(),st.end());
        
        return ans;
    }
};
