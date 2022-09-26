Question Link: https://leetcode.com/problems/allocate-mailboxes/

class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> dist; // total distance between [i,j] by placing '1 mail box' at any of the house
        
    int solve(vector<int>& houses, int i, int k){
        int n=houses.size();
        
        if(i == n){
            if(k == 0) return 0;
            return INT_MAX/2;
        }
        
        if(k == 0){
            if(i == n) return 0;
            return INT_MAX/2;
        }
        
        if(memo[i][k] != -1) return memo[i][k];
        
        int total_dist=INT_MAX/2;
        for(int j=i;j<n;j++){
            total_dist = min(total_dist, dist[i][j]+solve(houses,j+1,k-1));
        }
        return memo[i][k]=total_dist;
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        
        int n=houses.size();
        
        dist.resize(n,vector<int>(n,0));
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int mid=houses[(i+j)/2];
                
                for(int pos=i;pos<=j;pos++) dist[i][j] += abs(houses[pos]-mid);
            }
        }
        
        memo.resize(n,vector<int>(k+1,-1));
        return solve(houses, 0, k);
    }
};
