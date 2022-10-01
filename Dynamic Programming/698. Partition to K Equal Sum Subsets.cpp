Question Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/


// Approach 1:
class Solution {
public:
    
    bool solve(vector<int>& a, int n, int k, int sum, int target, int idx, vector<bool> &visited){
        if(k==0){
            for(int i=0;i<n;i++) if(visited[i]==false) return false;
            return true;
        }
        
        if(sum==target){
            return solve(a,n,k-1,0,target,0,visited);
        }
        
        for(int i=idx;i<n;i++){
            if(visited[i]==false && sum+a[i]<=target){
                visited[i]=true;
                if(solve(a,n,k,sum+a[i],target,i+1,visited)){
                    return true;
                }
                visited[i]=false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n=a.size();
        
        if(k>n) return false;
        
        int target=0;
        for(int i=0;i<n;i++) target+=a[i];
        
        if(target%k!=0) return false;
        target/=k;
        
        vector<bool> visited(n,false);
        return solve(a,n,k,0,target,0,visited);
    }
};


// Approach 2:
class Solution {
public:
    
    bool solve(vector<int>& a, int n, int k, int idx, vector<int> &sum, int sub, int target){
        if(idx==n){
            if(sub!=k-1) return false;
            for(int i=1;i<k;i++){
                if(sum[i]!=sum[i-1]) return false;
            }
            return true;
        }
        
        // start a new subset
        if(sub<k-1 && (n-idx>=sub-k)){
            sum[sub+1]=a[idx];
            bool newsub=solve(a,n,k,idx+1,sum,sub+1,target);
            if(newsub) return true;
            sum[sub+1]=0;
        }
        
        // become part of existing subset
        if(n-idx<k-sub) return false;
        for(int i=0;i<=sub;i++){
            sum[i]+=a[idx];
            if(sum[i]<=target){
                bool oldsub=solve(a,n,k,idx+1,sum,sub,target);
                if(oldsub) return true;
            } 
            sum[i]-=a[idx];
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n=a.size();
        int target=0;
        for(int i=0;i<n;i++) target+=a[i];
        if(target%k!=0) return false;
        target/=k;
        vector<int> sum(k,0);
        return solve(a,n,k,0,sum,0,target);
    }
};
