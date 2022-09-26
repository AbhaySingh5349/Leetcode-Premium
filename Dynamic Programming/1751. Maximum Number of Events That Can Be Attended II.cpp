Question Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/


// Approach 1:
class Solution {
public:
    
    int memo[1001][1001];
    
    int search(vector<vector<int>>& events, int end, int idx){
        int n=events.size();
        int l=idx, r=n-1;
        int i=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int start=events[m][0];
            if(start>end){
                i=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return i;
    }
    
    int profit(vector<vector<int>>& events, int n, int k, int idx){
        if(k==1){
            int val=0;
            while(idx<n) val=max(val,events[idx++][2]);
            return val;
        }
        
        if(memo[k][idx]!=-1) return memo[k][idx];
        
        int maxval=0;
        for(int i=idx;i<n;i++){
            int val=events[i][2]; // choosing current event
            
            int id=search(events, events[i][1], i+1); // looking for next possible event
            if(id!=-1){
                maxval = max(maxval,val+profit(events,n,k-1,id));
            }
            maxval=max(maxval,val);
        }
        return memo[k][idx]=maxval;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        
        memset(memo,-1,sizeof(memo));
        
        return profit(events,n,k,0);
    }
};


// Approach 2:
class Solution {
public:
    
    vector<vector<int>> memo;
    
    int search(vector<vector<int>>& events, int end, int idx){
        int n=events.size();
        int l=idx, r=n-1;
        int i=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int start=events[m][0];
            if(start>end){
                i=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return i;
    }
    
    int profit(vector<vector<int>>& events, int n, int k, int idx){
        if(idx >= n || k<=0) return 0;
        
        if(memo[idx][k]!=-1) return memo[idx][k];
        
        int maxval=0;
        
        // not attend
        maxval = profit(events, n, k, idx+1);
        
        // attend event
        int next_possible_idx = search(events, events[idx][1], idx+1);
        maxval = max(maxval, events[idx][2] + (next_possible_idx==-1 ? 0:profit(events,n,k-1,next_possible_idx)));
        
            
        return memo[idx][k]=maxval;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        
        memo.resize(n,vector<int>(k+1,-1));
        
        return profit(events,n,k,0);
    }
};
