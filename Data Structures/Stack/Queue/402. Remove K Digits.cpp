Question Link: https://leetcode.com/problems/remove-k-digits/


// Approach : 
class Solution {
public:
    
    // removing element having right greater element is not correct choice as it will bring greater 
    // value to 'more significant position'
    
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            while(k>0 && st.size()>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        // removing bigger numbers from end
        while(k>0 && st.size()>0){
            k--;
            st.pop();
        }
        
        string ans="";
        while(st.size()>0){
            char ch=st.top();
            ans+=ch;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0') i++;
        ans=ans.substr(i);
        return (ans.length()==0 ? "0":ans);
    }
};
