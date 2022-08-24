Question Link: https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    
    int getVal(string s){
        int val=0;
        for(int i=0;i<s.length();i++){
            val = val*10+(s[i]-'0');
        }
        return val;
    }
    
    vector<int> diffWaysToCompute(string s) {
        int n=s.length();
        if(n==1) return {getVal(s)};
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='-' || ch=='+' || ch=='*'){
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                
                for(int x : left){
                    for(int y: right){
                        if(ch=='-'){
                            ans.push_back(x-y);
                        }else if(ch=='+'){
                            ans.push_back(x+y);
                        }else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(getVal(s));
        return ans;
    }
};
