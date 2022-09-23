Question Link: https://leetcode.com/problems/longest-increasing-subsequence/

// Approach 1:
class Solution {
public:
    int lengthOfLIS(vector<int> &a) {
        int n=a.size();
        
        int dp[n];
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]) dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};

// Approach 2:
class Solution {
public:
    
    int search(vector<int> &lis, int val){
        int idx=-1;
        
        int l=0, r=lis.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(lis[m]>=val){
                idx=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return idx;
    }
    
    int lengthOfLIS(vector<int> &a) {
        int n=a.size();
        
        vector<int> lis;
        lis.push_back(a[0]);
        
        int ans=1;
        for(int i=1;i<n;i++){
            int pre=lis.back();
            
            if(a[i]>pre){
                lis.push_back(a[i]);
            }else{
                int idx=search(lis,a[i]); // ceil idx element
                if(idx!=-1) lis[idx]=a[i];
            }
            
            if(lis.size()>ans) ans=lis.size();
        }
        return ans;
    }
};
