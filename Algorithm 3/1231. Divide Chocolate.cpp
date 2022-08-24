Question Link: https://leetcode.com/problems/divide-chocolate/

// Approach 1: O(N^2 * k)

class Solution {
public:
    
    // Maximizing the minimum sub-array sum
    vector<vector<int>> memo;
    int solve(int n, vector<int> &presum, int prev, int count){
        if(memo[prev+1][count]!=-1) return memo[prev+1][count];
        
        if(count==1) return (presum[n-1]-(prev>=0 ? presum[prev]:0));
        
        int ans=INT_MIN;
        for(int i=prev+1;i<=n-count;i++){
            int firstSplit = presum[i]-(prev>=0 ? presum[prev]:0);
            int largestSplit = min(firstSplit,solve(n,presum,i,count-1));
            
            ans = max(ans,largestSplit);
        }
        return memo[prev+1][count]=ans;
    }
    
    int maximizeSweetness(vector<int>& a, int k) {
        int n=a.size();
        memo.resize(n,vector<int>(k+2,-1));
        
        vector<int> presum(n);
        presum[0]=a[0];
        for(int i=1;i<n;i++) presum[i]=presum[i-1]+a[i];
        
        return solve(n,presum,-1,k+1);
    }
};

// Approach 2:

class Solution {
public:
    
    // Maximizing the minimum sub-array sum
    bool isPossible(vector<int>& a, int minSweetness, int k){
        int n=a.size();
        int c=0;
        int sweetness=0;
        for(int i=0;i<n;i++){
            sweetness += a[i];
            if(sweetness >= minSweetness){
                sweetness = 0;
                c++;
            }
        }
        return (c>=k+1);
    }
    
    int maximizeSweetness(vector<int>& a, int k) {
        int r=accumulate(a.begin(),a.end(),0);
        r /= (k+1);
        
        int l=*min_element(a.begin(),a.end());
        
        while(l<r){
            int m = (r+l+1)/2;
            
            if(isPossible(a,m,k)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return r;
    }
};
