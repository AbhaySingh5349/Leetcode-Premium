Question Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    
    vector<int> memo;
    
    int search(vector<vector<int>>& events, int end, int idx){
        int n=events.size();
        int l=idx, r=n-1;
        int i=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int start=events[m][0];
            if(start>=end){
                i=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return i;
    }
    
    int getProfit(vector<vector<int>>& events, int n, int idx){
        if(idx == n) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        int maxval=0;
        
        // not attend
        maxval = getProfit(events, n, idx+1);
        
        // attend event
        int next_possible_idx = search(events, events[idx][1], idx+1);
        maxval = max(maxval, events[idx][2] + (next_possible_idx==-1 ? 0:getProfit(events,n,next_possible_idx)));
        
            
        return memo[idx]=maxval;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> events;
        for(int i=0;i<startTime.size();i++) events.push_back({startTime[i], endTime[i], profit[i]});
        
        int n=events.size();
        sort(events.begin(),events.end());
        
        memo.resize(n,-1);
        
        return getProfit(events,n,0);
    }
};
