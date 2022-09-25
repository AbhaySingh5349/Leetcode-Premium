Question Link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    
    void solve(vector<int> &a, int idx, int k, vector<vector<int>> &ans, vector<int> &sub){
        int n=a.size();
        
        if(idx==n){
            if(k==0) ans.push_back(sub);
            return;
        }
        
        // skip
        solve(a,idx+1,k,ans,sub);
        
        // take
        if(k>=a[idx]){
            sub.push_back(a[idx]);
            solve(a,idx,k-a[idx],ans,sub);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
        vector<vector<int>> ans;
        
        vector<int> sub;
        solve(a,0,k,ans,sub);
        
        return ans;
    }
};
