Question Link: https://leetcode.com/problems/make-array-strictly-increasing/


// Approach :
class Solution {
public:
    
    int ceilIdx(vector<int> &v, int val){
        int l=0, r=v.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            if(v[m]>val){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (v[l]>val ? l:v.size());
    }
    
    int solve(vector<int> &a, int idx, int prev, vector<int> &b, vector<unordered_map<int,int>> &memo){
        if(idx==a.size()) return 0;
        
        if(memo[idx].find(prev) != memo[idx].end()) return memo[idx][prev];
        
        int noReplace=INT_MAX/2;
        if(a[idx]>prev) noReplace = solve(a,idx+1,a[idx],b,memo);
        
        int replace=INT_MAX/2;
        int upperIdx = ceilIdx(b,prev);
        if(upperIdx != b.size()) replace=1+solve(a,idx+1,b[upperIdx],b,memo);
        
        return memo[idx][prev]=min(replace,noReplace);
    }
    
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(),b.end());
        
        vector<unordered_map<int,int>> memo(2001);
        
        int c = solve(a,0,INT_MIN,b,memo);
        
        return (c>=INT_MAX/2 ? -1:c);
    }
};
