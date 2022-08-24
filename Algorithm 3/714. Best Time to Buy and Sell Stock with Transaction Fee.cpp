Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

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
