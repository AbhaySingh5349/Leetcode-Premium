Question Link: https://leetcode.com/problems/word-break-ii/


// Approach 1:
class Solution {
public:
    
    void solve(set<string> st, string s, string op, vector<string> &ans){
        if(s.length()==0){
            ans.push_back(op);
            return;
        }
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i+1);
            string suf=s.substr(i+1);
            if(st.find(pre)!=st.end()){
                solve(st,suf,(op.length()==0 ? pre:op+" "+pre),ans);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        int n=dict.size();
        set<string> st;
        for(int i=0;i<n;i++) st.insert(dict[i]);
        
        vector<string> ans;
        solve(st,s,"",ans);
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    
    vector<string> solve(set<string> st, string s, map<string,vector<string>> &mp){
        if(mp.find(s)!=mp.end()) return mp[s];
        
        vector<string> v;
        if(st.find(s)!=st.end()) v.push_back(s);
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i+1);
            string suf=s.substr(i+1);
            if(st.find(pre)!=st.end()){
                vector<string> temp=solve(st,suf,mp);
                for(int j=0;j<temp.size();j++){
                    string ans=temp[j];
                    v.push_back(pre+" "+ans);
                }
            }
        }
        return mp[s]=v;
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        int n=dict.size();
        set<string> st;
        for(int i=0;i<n;i++) st.insert(dict[i]);
        
        map<string,vector<string>> mp;
        return solve(st,s,mp);
    }
};
