Question Link: https://leetcode.com/problems/house-robber-ii/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int> &a, int idx, int end, vector<int> &memo){
        if(idx >= end) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        // include
        int p1 = a[idx] + solve(a,idx+2,end,memo);
        
        // exclude
        int p2 = solve(a,idx+1,end,memo);
        
        return memo[idx] = max(p1,p2);
    }
    
    int rob(vector<int>& a) {
        if(a.size()==1) return a[0];
        
        vector<int> memo1(a.size(),-1), memo2(a.size(),-1);
        return max(solve(a,0,a.size()-1,memo1), solve(a,1,a.size(),memo2));
    }
};

// Approach 2:
class Solution {
public:
    int rob(vector<int> &a) {
        int n=a.size();
        if(n==1) return a[0];
        if(n==2) return max(a[0],a[1]);
        
        int dp1[n], dp2[n];
        
        dp1[0]=a[0], dp1[1]=max(a[0],a[1]);
        for(int i=2;i<n-1;i++) dp1[i]=max(dp1[i-1],dp1[i-2]+a[i]);
        
        dp2[1]=a[1], dp2[2]=max(a[1],a[2]);
        for(int i=3;i<n;i++) dp2[i]=max(dp2[i-1],dp2[i-2]+a[i]);
        
        return max(dp1[n-2],dp2[n-1]);
    }
};
