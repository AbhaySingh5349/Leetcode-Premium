Question Link: https://leetcode.com/problems/non-overlapping-intervals/


// Approach 1:
class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int search(vector<vector<int>> &a, int idx){
        int l=0, r=idx-1;
        int ans=-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m][1]<=a[idx][0]){
                l=m+1;
                ans=m;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),compare);
        
        int n=a.size();
        int dp[n];
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            dp[i]=max(1,dp[i-1]);
            int idx=search(a,i);
            
            if(idx!=-1) dp[i]=max(dp[i],1+dp[idx]);
            ans=max(ans,dp[i]);
        } 
        return n-ans;
    }
};


// Approach 2:
class Solution {
public:
    
    static bool compare(vector<int> &a, vector<int> &b){
    	if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>> &a) {
        int n=a.size();
        
        sort(a.begin(),a.end(),compare);
        
        int c=0;
        int s=a[0][0], e=a[0][1];
        for(int i=1;i<n;i++){
            int si=a[i][0], ei=a[i][1];
            if(si<e){
                c++;
            }else{
                e=max(e,ei);
            }
        }
        return c;
    }
};
