Question Link: https://leetcode.com/problems/word-break/


// Approach 1:
class Solution {
public:
    
    bool check(string s, set<string> &st, map<string,bool> &mp){
        int n=s.length();
        
        if(n==0) return true;
        
        if(mp.find(s)!=mp.end()) return mp[s];
        
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i+1);
            string suf=s.substr(i+1);
            
            if(st.find(pre)!=st.end()){
                if(st.find(suf)!=st.end() || check(suf,st,mp)==true) return mp[s]=true;
            }
        }
        return mp[s]=false;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
        set<string> st;
        map<string,bool> mp;
        for(int i=0;i<dict.size();i++){
            st.insert(dict[i]);
            mp[dict[i]]=true;
        }
        
        return check(s,st,mp); 
    }
};


// Approach 2:
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--){
            for(string w : dict){
                if(i+w.length() <= n && s.substr(i,w.length()) == w){
                    dp[i]=dp[i+w.length()];
                    if(dp[i]==true) break;
                }
            }
        }
        return dp[0];
    }
};
