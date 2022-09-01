Question Link: https://leetcode.com/problems/factor-combinations/

// Approach 1:
class Solution {
public:
    
    void solve(int n, int factor, vector<int> &cur, vector<vector<int>> &ans){
        if(n==1){
            if(cur.size()>1) ans.push_back(cur);
            return;
        }
        
        for(int f=factor;f<=n;f++){
            if(n%f == 0){
                cur.push_back(f);
                solve(n/f,f,cur,ans);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        solve(n, 2, cur, ans);
        
        return ans;
    }
};

// Approach 2:
class Solution {
public:
    
    void solve(int n, int factor, vector<int> cur, vector<vector<int>> &ans){
        for(int f=factor;f*f<=n;f++){
            if(n%f == 0){
                vector<int> new_cur = cur;
                new_cur.push_back(f);
                solve(n/f,f,new_cur,ans);
                new_cur.push_back(n/f);
                
                ans.push_back(new_cur);
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        
        solve(n, 2, cur, ans);
        
        return ans;
    }
};
