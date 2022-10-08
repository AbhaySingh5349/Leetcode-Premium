Question Link: https://leetcode.com/problems/longest-valid-parentheses/


// Approach 1:
class Solution {
public:
    
    bool isValid(string s, int i, int j){
        stack<char> st;
        for(int k=i;k<=j;k++){
            char ch=s[k];
            
            if(ch=='('){
                st.push(ch);
            }else{
                if(st.size()==0 || st.top() != '(') return false;
                st.pop();
            }
        }
        return (st.size()==0);
    }
    
    int longestValidParentheses(string s) {
        int  n=s.length();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j+=2){
                if(isValid(s,i,j)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        
        return ans;
    }
};


// Approach 2:
class Solution {
public:
    int longestValidParentheses(string s) {
        int  n=s.length();
        
        int ans=0;
        int open=0, close=0;
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                open++;
            }else{
                close++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }else if(close>open){
                open=close=0;
            }
        }
        
        open=0, close=0;
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            if(ch==')'){
                close++;
            }else{
                open++;
            }
            if(open==close){
                ans=max(ans,open+close);
            }else if(open>close){
                open=close=0;
            }
        }
        return ans;
    }
};
