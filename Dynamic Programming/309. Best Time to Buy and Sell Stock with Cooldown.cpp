Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Approach 1:
class Solution {
public:
    
    int solve(vector<int>& prices, int idx, bool prev, vector<vector<int>> &memo){
        if(idx>=prices.size()) return 0;
        
        if(memo[idx][prev] != -1) return memo[idx][prev];
        
        int p1=0, p2=0;
        
        // can buy
        if(prev == false){
            // decide to buy
            p1 = solve(prices, idx+1, true, memo) - prices[idx];
            
            // skip buying
            p2 = solve(prices, idx+1, false, memo);
        }else{
            // decide to sell
            p1 = solve(prices, idx+2, false, memo) + prices[idx];
            
            // skip selling
            p2 = solve(prices, idx+1, prev, memo);
        }
        memo[idx][prev] = max(p1,p2);
        return memo[idx][prev];
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2,-1));
        return solve(prices,0,0,memo);
    }
};

// Approach 2:
class Solution {
public:
    
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        
        int buy[n]; // max profit assuming buying at every index
        int sell[n]; // max profit assuming selling at every index
        
        buy[0]=-a[0], buy[1]=-min(a[0],a[1]);
        
        sell[0]=0, sell[1]=max(0,a[1]-a[0]);
        
        for(int i=2;i<n;i++){
            buy[i]=max(buy[i-1],sell[i-2]-a[i]);
            sell[i]=max(sell[i-1],buy[i-1]+a[i]);
        }
        return sell[n-1];
    }
};
