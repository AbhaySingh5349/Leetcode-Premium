Question Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/


// Approach : 
class Solution {
public:
    
    #define ll long long
    
    int shortestSubarray(vector<int>& a, int k) {
        int n=a.size();
        
        deque<pair<ll int,int>> dq; // cumulative sum, index
        
        ll int sum=0;
        int ans=n+1;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            
            if(sum>=k) ans=min(ans,i+1); // sum from start to ith index
            
            // reduce window size with sum >= k
            pair<ll int,int> cur={-1,-1};
            while(dq.size()>0 && (sum-dq.front().first >= k)){
                cur=dq.front();
                dq.pop_front();
            }
            
            if(cur.second != -1) ans=min(ans,i-cur.second);
            
            // maintain monotonic non-decreasing order of deque
            while(dq.size()>0 && sum <= dq.back().first) dq.pop_back();
            
            dq.push_back({sum,i});
        }
        
        return (ans==n+1 ? -1:ans);
    }
};
