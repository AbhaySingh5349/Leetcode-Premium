Question Link: https://leetcode.com/problems/minimum-cost-for-tickets/

// Approach 1:
class Solution {
public:
    
    int memo[501];
    set<int> st;
    
    int val(vector<int>& days, vector<int>& cost, int n, int idx){
        if(idx>days[n-1]) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        int ans=INT_MAX;
        if(st.find(idx)==st.end()){
            ans=val(days,cost,n,idx+1);
        }else{
            ans=min(ans,cost[0]+val(days,cost,n,idx+1));
            ans=min(ans,cost[1]+val(days,cost,n,idx+7));
            ans=min(ans,cost[2]+val(days,cost,n,idx+30));
        }
        
        return memo[idx]=ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        memset(memo,-1,sizeof(memo));
        int n=days.size();
        
        for(int i=0;i<n;i++) st.insert(days[i]);
        
        return val(days,cost,n,days[0]);
    }
};

// Approach 2:
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(days[i]);
        }
        
        int dp[366];
        for(int i=1;i<366;i++) dp[i]=INT_MAX;
        dp[0]=0;
        
        for(int i=1;i<=days[n-1];i++){
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
            }else{
                dp[i]=min(dp[i],cost[0]+dp[i-1]);
                dp[i]=min(dp[i],cost[1]+dp[max(0,i-7)]);
                dp[i]=min(dp[i],cost[2]+dp[max(0,i-30)]);
            }
        }
        return dp[days[n-1]];
    }
};
