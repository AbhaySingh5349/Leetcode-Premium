Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// Approach 1:
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

// Approach 2:
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n<2) return 0;
        
        int left[n]; // max possible profit if perform 1 transaction from [0,i]
        left[0]=0;
        int minl=a[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],a[i]-minl);
            minl=min(minl,a[i]);
        }
        
        int right[n]; // max possible profit if perform 1 transaction from [i,n-1]
        right[n-1]=0;
        int maxr=a[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],maxr-a[i]);
            maxr=max(maxr,a[i]);
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,left[i]+right[i+1]);
            ans=max(ans,max(left[i],right[i]));
        }
        
        return ans;
    }
};
