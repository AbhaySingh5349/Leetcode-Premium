Question Link: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    
    vector<vector<bool>> dp;
    
    void solve(string s, int idx, vector<vector<string>> &ans, vector<string> &sub){
        int n=s.length();
        if(idx==n){
            ans.push_back(sub);
            return;
        }
        
        for(int i=idx;i<n;i++){
            if(dp[idx][i]==true){
                string pre=s.substr(idx,i-idx+1);
                
                sub.push_back(pre);
                solve(s,i+1,ans,sub);
                sub.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        
        dp.resize(n,vector<bool> (n,false));
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                
                if(s[i]==s[j]) dp[i][j] = (j-i<2 || dp[i+1][j-1]);
            }
        }
        
        vector<vector<string>> ans;
        vector<string> sub;
        solve(s,0,ans,sub);
        
        return ans;
    }
};
