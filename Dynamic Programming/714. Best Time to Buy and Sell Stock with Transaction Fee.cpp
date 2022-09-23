Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int>& prices, int idx, bool prev, int fee, vector<vector<int>> &memo){
        if(idx>=prices.size()) return 0;
        
        if(memo[idx][prev] != -1) return memo[idx][prev];
        
        int p1=0, p2=0;
        
        // can buy
        if(prev == false){
            // decide to buy
            p1 = solve(prices, idx+1, true, fee, memo) - prices[idx];
            
            // skip buying
            p2 = solve(prices, idx+1, false, fee, memo);
        }else{
            // decide to sell
            p1 = solve(prices, idx+1, false, fee, memo) + prices[idx]-fee;
            
            // skip selling
            p2 = solve(prices, idx+1, prev, fee, memo);
        }
        memo[idx][prev] = max(p1,p2);
        return memo[idx][prev];
    }
    
    int maxProfit(vector<int> &prices, int fee) {
        vector<vector<int>> memo(prices.size(), vector<int>(2,-1));
        return solve(prices,0,0,fee,memo);
    }
};

// Approach 2:
class Solution {
public:
    int maxProfit(vector<int> &a, int fee) {
        int n=a.size();
        
        if(n==1) return 0;
        
        int buy[n], sell[n];
        buy[0]=-a[0], buy[1]=-min(a[0],a[1]);
        sell[0]=0, sell[1]=max(0,a[1]-a[0]-fee);
        
        for(int i=2;i<n;i++){
            buy[i]=max(buy[i-1],sell[i-1]-a[i]);
            sell[i]=max(sell[i-1],buy[i-1]+a[i]-fee);
        }
        
        return sell[n-1];
    }
};
