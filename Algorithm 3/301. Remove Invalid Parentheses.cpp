Question Link: https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    
    int minRemovals(string s){
        int i, n=s.length();
        stack<char> st;
        for(i=0;i<n;i++){
            char ch=s[i];
            if(isalpha(ch)){
                continue;
            }
            if(ch=='('){
                st.push(ch);
            }else{
                if(st.size()==0 || st.top()==')'){
                    st.push(ch);
                }else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
    
    void solve(string s, vector<string> &ans, int removal, unordered_map<string,bool> &mp){
        if(s.length()==0 || mp.find(s)!=mp.end()) return;
        
        mp[s]=true;
        if(removal==0 && minRemovals(s)==0){
            ans.push_back(s);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i);
            string suf=s.substr(i+1);
            
            string sub=pre+suf;
            solve(sub,ans,removal-1,mp);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int removals=minRemovals(s);
        
        vector<string> ans;
        unordered_map<string,bool> mp;
        solve(s,ans,removals,mp);
        if(ans.size()==0) ans.push_back("");
        return ans;
    }
};
