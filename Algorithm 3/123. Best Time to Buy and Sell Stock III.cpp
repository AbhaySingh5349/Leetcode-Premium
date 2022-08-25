Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    
    int traverseStock(vector<int> &prices, int idx, int prevState, int count, vector<vector<vector<int>>> &dp){
        if(idx==prices.size() || count==2) return 0;
        
        int p1=0, p2=0;
        
        if(dp[idx][prevState][count]!=-1) return dp[idx][prevState][count];
        
        if(prevState==0){ // can buy
            p1=-prices[idx]+traverseStock(prices, idx+1, 1, count, dp); // buying
            
            p2=0+traverseStock(prices, idx+1, 0, count, dp); // skip buying
        } else{ // can sell
            p1=prices[idx]+traverseStock(prices, idx+1, 0, count+1, dp); // selling
            
            p2=0+traverseStock(prices, idx+1, 1, count, dp); // skip selling
        }
        
        return dp[idx][prevState][count]=max(p1, p2);
    }
    
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        
        return traverseStock(prices, 0, 0, 0, dp);
    }
};
