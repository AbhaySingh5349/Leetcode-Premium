Question Link: https://leetcode.com/problems/decode-string/

// Approach 1:

Time Complexity: O(maxK^(countK) ⋅ n), where maxK is the maximum value of k and n is the length of a given string s.
Example, for s = 20[a10[bc]], maxK is 20, countK is 2 as there are 2 nested k values (20 and 10) .
Also, there are 2 encoded strings a and bc with maximum length of encoded string ,n as 2

class Solution {
public:
    
    string getSub(stack<char> &st){
        string sub="";
        while(st.size()>0 && st.top()!='['){
            sub += st.top();
            st.pop();
        }
        st.pop();
        reverse(sub.begin(),sub.end());
        
        return sub;
    }
    
    int getFactor(stack<char> &st){
        int k=0, base = 1;
        while(st.size()>0 && isdigit(st.top())){
            k = k + (st.top()-'0')*base;
            st.pop();
            base*=10;
        }
        
        return k;
    }
    
    string decodeString(string s) {
        int n=s.length();
        
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string sub=getSub(st);
                int k=getFactor(st);
                
                string update="";
                while(k--) update += sub;
                for(int j=0;j<update.length();j++) st.push(update[j]);
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.size()>0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

// Approach 2:

Time Complexity: O(maxK⋅n), where maxK is the maximum value of k and n is the length of a given string s.
We traverse a string of size n and iterate k times to decode each pattern of form k[string]. 

class Solution {
public:
    
    string decodeString(string s) {
        int n=s.length();
        
        stack<string> strStack;
        stack<int> kStack;
        
        string cur="";
        int factor=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='['){
                strStack.push(cur);
                kStack.push(factor);
                cur="", factor=0;
            }else if(ch==']'){
                int k=kStack.top();
                kStack.pop();
                
                string decoded=strStack.top();
                strStack.pop();
                while(k--) decoded += cur;
                
                cur=decoded;
            }else if(isdigit(ch)){
                factor = factor*10 + (ch-'0');
            }else{
                cur += ch;
            }
        }
        return cur;
    }
};
