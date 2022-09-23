Question Link: https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/

// Approach 1:
class Solution {
public:
    
    int final_ans;
    int solve(vector<int> &a, int idx, bool can_square, vector<vector<int>> &memo){
        int n=a.size();
        if(idx == n) return 0;
        
        if(memo[idx][can_square]!=INT_MIN) return memo[idx][can_square];
        
        int ans=INT_MIN;
        
        if(can_square) ans = max(a[idx]*a[idx]+solve(a,idx+1,false,memo), a[idx]*a[idx]);
        ans = max(ans, max(a[idx]+solve(a,idx+1,can_square,memo), a[idx]));
        
        final_ans=max(final_ans,ans);
        return memo[idx][can_square]=ans;
    }
    
    int maxSumAfterOperation(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> memo(n, vector<int>(2,INT_MIN));
        
        final_ans=INT_MIN;
        solve(a,0,true,memo);
        
        return final_ans;
    }
};

// Approach 2:
class Solution {
public:
    
    int maxSumAfterOperation(vector<int>& a) {
        int n=a.size();
        vector<int> squared(n), not_squared(n);
        squared[0]=a[0]*a[0], not_squared[0]=a[0];
        
        int ans=squared[0];
        for(int i=1;i<n;i++){
            not_squared[i]=max(not_squared[i-1]+a[i], a[i]);
            squared[i]=max(a[i]*a[i],max(squared[i-1]+a[i],a[i]*a[i]+not_squared[i-1]));
            
            ans=max(ans,max(squared[i],not_squared[i]));
        }
        return ans;
    }
};
