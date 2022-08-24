Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

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
