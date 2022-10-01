Question Link: https://leetcode.com/problems/stone-game-iii/


// Approach 1:
class Solution {
public:
    
    vector<int> pre;
    vector<int> memo;
    
    int solve(vector<int>& a, int idx){
        int n=a.size();
        
        if(idx==n) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        int ans=INT_MIN;
        
        for(int i=idx;i<min(n,idx+3);i++){
            int val=(pre[i]-(idx>0 ? pre[idx-1]:0));
            ans=max(ans,val-solve(a,i+1));
        }
        
        return memo[idx]=ans;
    }
    
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        
        pre.resize(n);
        memo.resize(n,-1);
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        
        int val=solve(a,0);
    
        if(val>0) return "Alice";
        if(val<0) return "Bob";
        return "Tie";
    }
};


// Approach 2:
class Solution {
public:
    
    map<int,int> m;
    
    int solve(vector<int>& a, int n, int idx){
        if(idx>=n) return 0;
        
        if(m.find(idx)!=m.end()){
            return m[idx];
        }
        
        int d=INT_MIN;
        if(idx==n-1){
            int t1=a[idx];
            d = t1;
        }else if(idx==n-2){
            int t2=a[idx]+a[idx+1];
            int t1=a[idx]-a[idx+1];
            d=max(d,max(t1,t2));
        }else{
            int t3=a[idx]+a[idx+1]+a[idx+2]-solve(a,n,idx+3);
            int t2=a[idx]+a[idx+1]-solve(a,n,idx+2);
            int t1=a[idx]-solve(a,n,idx+1);
            d=max(d,max(t3,max(t1,t2)));
        }
        
        return m[idx]=d;
    }
    
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        
        int d=solve(a,n,0);
        if(d>0) return "Alice";
        if(d<0) return "Bob";
        return "Tie";
    }
};


// Approach 3:
class Solution {
public:
    
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        int dp[n+1];
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i]=a[i];
            }else if(i==n-2){
                dp[i]=max(a[i]+a[i+1],a[i]-dp[i+1]);
            }else{
                dp[i]=max(a[i]+a[i+1]+a[i+2]-dp[i+3],max(a[i]+a[i+1]-dp[i+2],a[i]-dp[i+1]));
            }
        }
        
        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";
    }
};
