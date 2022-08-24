Question Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    
    vector<vector<int>> memo;
    int solve(vector<int>& a, vector<int> &presum, int prev, int count){
        int n=a.size();
        if(memo[prev+1][count]!=-1) return memo[prev+1][count];
        
        if(count==1) return (presum[n-1]-(prev>=0 ? presum[prev]:0));
        
        int ans=INT_MAX;
        for(int i=prev+1;i<=n-count;i++){
            int firstSplit = presum[i]-(prev>=0 ? presum[prev]:0);
            int largestSplit = max(firstSplit,solve(a,presum,i,count-1));
            
            ans = min(ans,largestSplit);
        }
        return memo[prev+1][count]=ans;
    }
    
    int splitArray(vector<int>& a, int k) {
        int n=a.size();
        memo.resize(n,vector<int>(k+1,-1));
        
        vector<int> presum(n);
        presum[0]=a[0];
        for(int i=1;i<n;i++) presum[i]=presum[i-1]+a[i];
        
        return solve(a,presum,-1,k);
    }
};
